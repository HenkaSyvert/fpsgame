#include "physics/boundingbox.hpp"

using namespace Missan;

// PUBLIC

std::vector<glm::vec3> BoundingBox::GetVertices() {
	std::vector<glm::vec3> v;
	auto x = size.x / 2, y = size.y / 2, z = size.z / 2;
	v.push_back({  x, -y, -z });
	v.push_back({  x, -y,  z });
	v.push_back({  x,  y, -z });
	v.push_back({  x,  y,  z });
	v.push_back({ -x, -y, -z });
	v.push_back({ -x, -y,  z });
	v.push_back({ -x,  y, -z });
	v.push_back({ -x,  y,  z });
	return v;
}

std::vector<glm::vec3> BoundingBox::GetNormals() {
	std::vector<glm::vec3> v;
	v.push_back({ 1,0,0 });
	v.push_back({ 0,1,0 });
	v.push_back({ 0,0,1 });
	return v;
}

std::vector<glm::vec3> BoundingBox::GetEdgeVectors() {
	// Just happens to be the same
	return GetNormals();
}

void BoundingBox::EncapsulatePoints(std::vector<glm::vec3>& points) {
	float x = 0, y = 0, z = 0;
	for (auto& p : points) {
		x = std::max(abs(p.x), x);
		y = std::max(abs(p.y), y);
		z = std::max(abs(p.z), z);
	}
	size = { 2 * x, 2 * y, 2 * z };
}


