#include <glm/gtc/matrix_transform.hpp>

#include "Camera.h"

namespace oktan
{
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