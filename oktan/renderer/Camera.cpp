#include <glm/gtc/matrix_transform.hpp>

#include "Camera.h"

namespace oktan
{
	PerspectiveCamera::PerspectiveCamera(float fov, float width, float height, float near, float far)
		: m_Projection(glm::perspective(glm::radians(fov), width / height, near, far))
	{
		m_ViewProjection = m_Projection * m_View;
		RecalculateView();
	}

	void PerspectiveCamera::SetProjection(float width, float height, float fov, float near, float far)
	{
		m_Projection = glm::perspective(glm::radians(fov), width / height, near, far);
	}

	void PerspectiveCamera::SetPosition(glm::vec3 &pos)
	{
		m_Position = pos;
		RecalculateView();
	}

	void PerspectiveCamera::SetTarget(glm::vec3 &target)
	{
		m_Target = target;
		RecalculateView();
	}

	void PerspectiveCamera::RecalculateView()
	{
		m_View = glm::lookAt(m_Position, m_Target, UPVEC);
		m_ViewProjection = m_Projection * m_View;
	}

	OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top)
		: m_Projection(glm::ortho(left, right, bottom, top))
	{
		m_ViewProjection = m_Projection * m_View;
	}
	void OrthographicCamera::SetProjection(float left, float right, float bottom, float top)
	{
		m_Projection = glm::ortho(left, right, bottom, top);
		m_ViewProjection = m_Projection * m_View;
	}

	void OrthographicCamera::SetPosition(glm::vec3& pos)
	{
		m_Position = pos;
		RecalculateView();
	}

	void OrthographicCamera::SetRotationAngle(float angle)
	{
		m_Rotation = angle;
		RecalculateView();
	}

	void OrthographicCamera::RecalculateView()
	{
		// Rotate then translate, NOTE: order is reversed because of "MATHEMATICAL" reasons
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), m_Position) *
			glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation), glm::vec3(0, 0, 1));

		m_View = glm::inverse(transform);
		m_ViewProjection = m_Projection * m_View;
	}

}