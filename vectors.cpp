#include "vectors.h"

Vec2 Vec2::operator/(const Vec2& other) const
{
    return Vec2(x / other.x, y / other.y);
}
Vec2 Vec2::operator/(const float divisor) const
{
    return Vec2(x / divisor, y / divisor);
}

Vec3 Vec3::normalized()
{
    float vectorLength = this->length();
    return Vec3(x / vectorLength, y / vectorLength, z / vectorLength);
}

void Vec3::normalizeInPlace()
{
    *this = this->normalized();
}

Vec2 Vec3::to2D()
{
    return Vec2(x, y);
}

Vec3::operator float* (void) {
	return &this->x;
}
float Vec3::operator[](const int index) const {
	return (&x)[index];
}
float& Vec3::operator[](const int index) {
	return (&this->x)[index];
}
float Vec3::operator*(const Vec3& a) const {
	return x * a.x + y * a.y + z * a.z;
}
Vec3 Vec3::operator-() const {
	return Vec3(-x, -y, -z);
}
Vec3& Vec3::operator=(const Vec3& a)
{
	x = a.x;
	y = a.y;
	z = a.z;
	return *this;
}
Vec3 Vec3::operator*(const float a) const {
	return Vec3(x * a, y * a, z * a);
}
Vec3 operator*(const float a, const Vec3 b) {
	return Vec3(b.x * a, b.y * a, b.z * a);
}

bool Vec3::isWithinRange(float center, float errorMargin) const
{
	float max = center + errorMargin;
	float min = center - errorMargin;

	return (min <= x && x <= max)
		&& (min <= y && y <= max)
		&& (min <= z && z <= max);
}