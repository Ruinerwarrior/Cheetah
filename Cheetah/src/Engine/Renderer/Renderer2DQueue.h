#ifndef CHEETAH_ENGINE_RENDERER_RENDERER2DQUEUE_H_
#define CHEETAH_ENGINE_RENDERER_RENDERER2DQUEUE_H_

#include "Texture.h"
#include "Shader.h"
#include "Math/Mat4x4.h"
#include "Math/Rgba.h"

#include <vector>
#include <memory>
#include <map>
#include <string>

namespace cheetah
{
	struct Renderer2DQueueItem
	{
		unsigned int id;
		float z = 0.0f;
		Shader* shader;
		Texture* texture;
	};

	struct Renderer2DMatrixQueueItem
	{
		unsigned int id;
		math::Mat4x4f transform;
		math::Rgba color;
	};

	struct Renderer2DQueueAddParams
	{
		float z = 0.0f;
		Texture* texture;
		Shader* shader;;
	};

	class Renderer2DQueue
	{
	public:
		Renderer2DQueue() = default;
		~Renderer2DQueue() = default;
		void add(Renderer2DQueueAddParams params, math::Mat4x4f transform, math::Rgba color = math::Rgba(1.0f));
		void sort();
		void clear();
	public:
		static std::vector<Renderer2DQueueItem> s_queue;
		static std::vector<Renderer2DMatrixQueueItem> s_matrixQueue;
	private:
		bool compare(const Renderer2DQueueItem& a, const Renderer2DQueueItem& b);
	};
}


#endif // !CHEETAH_ENGINE_RENDERER_RENDERER2DQUEUE_H_
