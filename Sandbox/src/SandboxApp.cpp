#include "Portakal.h"


class Sandbox : public Portakal::Application {
	public:
		Sandbox() {

		}
		~Sandbox() {

		}
};


Portakal::Application* Portakal:: CreateApplication() {
	return new Sandbox;
}