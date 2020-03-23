#include <glm/gtc/matrix_transform.hpp>

#include "Camera.h"

namespace oktan
{
	PerspectiveCamera::PerspectiveCamera(float fov, float width, float height, float nearPlane, float farPlane)
		: m_Projection(glm::perspective(glm::radians(fov), width / height, nearPlane, farPlane))
	{
		m_ViewProjection = m_Projection * m_View;
		RecalculateView();
	}

	void PerspectiveCamera::SetProjection(float width, float height, float fov, float nearPlane, float farPlane)
	{
		m_Projection = glm::perspective(glm::radians(fov), width / height, nearPlane, farPlane);
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

	OrthographicCamera::OrthographicCamera(float fov, float left, float right, float bottom, float top)
	{
		float distance = 4.0f;
		float scale = glm::abs(glm::tan(fov / 2) * distance);
		m_Projection = glm::ortho(-scale, scale, -scale, scale, bottom, top);
		m_ViewProjection = m_Projection * m_View;
		OK_LOG_INFO("Created orthographic camera with scale : {}", scale);
	}

	void OrthographicCamera::SetProjection(float fov, float left, float right, float bottom, float top)
	{
		float distance = 4.0f;
		float scale = glm::abs(glm::tan(fov / 2) * distance);
		m_Projection = glm::ortho(-scale, scale, -scale, scale, bottom, top);
		m_ViewProjection = m_Projection * m_View;
		OK_LOG_INFO("Set orthographic camera's scale : {}", scale);
	}

	void OrthographicCamera::SetPosition(glm::vec3& pos)
	{
		m_Position = pos;
		RecalculateView();
	}

	void OrthographicCamera::SetTarget(glm::vec3 &target)
	{
		m_Target = target;
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

		m_View = glm::lookAt(m_Position, m_Target, UPVEC);
		m_ViewProjection = m_Projection * m_View;
	}

}