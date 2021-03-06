#ifndef _OK_CAMERA_H_
#define _OK_CAMERA_H_

#include <glm/glm.hpp>
#include <oktan/Core.h>

namespace oktan
{
	class PerspectiveCamera
	{
	public:
		PerspectiveCamera(float fov, float width, float height, float nearPlane, float farPlane);
		virtual ~PerspectiveCamera() = default;

		glm::mat4 GetProjectionMatrix() const { return m_Projection; }
		glm::mat4 GetViewMatrix() const { return m_View; }
		glm::mat4 GetViewProjectionMatrix() const { return m_ViewProjection; }
		glm::vec3 GetPosition() const { return m_Position; }
		glm::vec3 GetTarget() const { return m_Target; }

		void SetProjection(float fov, float width, float height, float nearPlane, float farPlane);
		void SetPosition(glm::vec3 &pos);
		void SetTarget(glm::vec3 &target);

	protected:
		void RecalculateView();

	private:
		const glm::vec3 UPVEC = { 0.0f, 1.0f, 0.0f };
		glm::mat4 m_Projection;
		glm::mat4 m_View;
		glm::mat4 m_ViewProjection;

		glm::vec3 m_Position = { 0.0f, 0.0f, 0.0f };
		glm::vec3 m_Target = { 0.0f, 0.0f, 0.0f };
	};

	class OrthographicCamera
	{
	public:
		OrthographicCamera(float fov, float left, float right, float bottom, float top);
		virtual ~OrthographicCamera() = default;

		glm::mat4 GetProjectionMatrix() const { return m_Projection; }
		glm::mat4 GetViewMatrix() const { return m_View; }
		glm::mat4 GetViewProjectionMatrix() const { return m_ViewProjection; }
		glm::vec3 GetPosition() const { return m_Position; }
		glm::vec3 GetTarget() const { return m_Target; }
		float GetRotationAngle() const { return m_Rotation; }

		void SetProjection(float fov, float left, float right, float bottom, float top);
		void SetPosition(glm::vec3& pos);
		void SetTarget(glm::vec3 &target);
		void SetRotationAngle(float angle);

	protected:
		void RecalculateView();

	private:
		const glm::vec3 UPVEC = { 0.0f, 1.0f, 0.0f };
		glm::mat4 m_Projection;
		glm::mat4 m_View;
		glm::mat4 m_ViewProjection;

		glm::vec3 m_Position = { 0.0f, 0.0f, 0.0f };
		glm::vec3 m_Target = { 0.0f, 0.0f, 0.0f };
		float m_Rotation = 0.0f;
	};
}

#endif
