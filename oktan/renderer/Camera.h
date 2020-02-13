#ifndef _OK_CAMERA_H_
#define _OK_CAMERA_H_

#include <glm/glm.hpp>

namespace oktan
{
	class OrthographicCamera
	{
	public:
		OrthographicCamera(float left, float right, float bottom, float top);
		virtual ~OrthographicCamera() = default;

		glm::mat4 GetProjectionMatrix() const { return m_Projection; }
		glm::mat4 GetViewMatrix() const { return m_View; }
		glm::mat4 GetViewProjectionMatrix() const { return m_ViewProjection; }
		glm::vec3 GetPosition() const { return m_Position; }
		float GetRotationAngle() const { return m_Rotation; }

		void SetProjection(float left, float right, float bottom, float top);
		void SetPosition(glm::vec3& pos);
		void SetRotationAngle(float angle);

	protected:
		void RecalculateView();

	private:
		glm::mat4 m_Projection;
		glm::mat4 m_View;
		glm::mat4 m_ViewProjection;

		glm::vec3 m_Position = { 0.0f, 0.0f, 0.0f };
		float m_Rotation = 0.0f;

	};
}

#endif