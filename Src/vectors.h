#pragma once

typedef float vec_t;
typedef vec_t vec2_t[2];
typedef vec_t vec3_t[3];
typedef vec_t vec4_t[4];
typedef vec_t vec5_t[5];
struct Vec2;
struct Vec3;

struct Vec2
{
	float x, y;
	Vec2() { x = 0.0f;  y = 0.0f; };
	Vec2(float vec_x, float vec_y) { x = vec_x; y = vec_y; }
	Vec2(const Vec2& v) { x = v.x; y = v.y; }
	inline Vec2 operator + (const Vec2& v) const { return Vec2(x + v.x, y + v.y); }
	inline Vec2 operator - (const Vec2& v) const { return Vec2(x - v.x, y - v.y); }
	inline Vec2 operator * (const Vec2& v) const { return Vec2(x * v.x, y * v.y); }
	inline bool operator == (const Vec2& v) const { return x == v.x && y == v.y; }
	inline bool operator != (const Vec2& v) const { return x != v.x && y != v.y; }
	inline Vec2& operator += (const Vec2& v) { this->x += v.x; this->y += v.y; }
	inline Vec2& operator -= (const Vec2& v) { this->x += v.x; this->y += v.y; }
	inline Vec2& operator *= (const Vec2& v) { this->x += v.x; this->y += v.y; }
	inline Vec2& operator /= (const Vec2& v) { this->x += v.x; this->y += v.y; }
	inline float& operator [] (int index) { if (index == 0) return x; if (index == 1) return y; static float dummy = FLT_MIN; float& invalid_ref = dummy; return invalid_ref; }
	Vec2 operator/(const Vec2& other) const;
	Vec2 operator/(const float divisor) const;
	const float& operator [] (int index) const { if (index == 0) return x;  if (index == 1) return y; return FLT_MIN; }
	ImVec2 toImVec2() const { return ImVec2(x, y); }
	inline float Length() const { return sqrt((x * x) + (y * y)); }
	inline float Dist2D(const Vec2 v) { return (Vec2(x, y) - Vec2(v.x, v.y)).Length(); }
	inline float Dist2D(const ImVec2 v) { return (Vec2(x, y) - Vec2(v.x, v.y)).Length(); }
	static Vec2 toVec2(const ImVec2& v) { return Vec2(v.x, v.y); }
	inline Vec2 scale(float scalar) { return Vec2(x * scalar, y * scalar); }
	inline bool isNull() const { return x == 0 && y == 0; }
	inline bool isAnyNull() const { return this->x == 0.0f || this->y == 0.0f; }
	inline void setNull() { this->x = 0; this->y = 0; }
	inline Vec2 add(Vec2 other) { return Vec2(x + other.x, y + other.y); }
	inline Vec2 sub(Vec2 other) { return Vec2(x - other.x, y - other.y); }
	inline Vec2 multiply(Vec2 other) { return Vec2(this->x * other.x, this->y * other.y); }
	inline Vec2 asAbsolute() const { return Vec2(fabs(x), fabs(y)); }
	inline Vec2 mirror() { return Vec2(x * -1.0f, y * -1.0f); }
	inline Vec2 snapVector() const { return Vec2(roundf(x), roundf(y)); }
};
struct Vec3
{
	float x, y, z;
	Vec3() { x = 0.0f; y = 0.0f; z = 0.0f; };
	Vec3(vec3_t vec) { x = vec[0]; y = vec[1]; z = vec[2]; }
	Vec3(float vec_x, float vec_y, float vec_z) { x = vec_x; y = vec_y; z = vec_z; }
	Vec3(const Vec3& v) { x = v.x; y = v.y; z = v.z; }
	operator float* ();
	float operator [] (const int index) const;
	float& operator [] (const int index);
	Vec3 operator-() const;
	Vec3& operator=(const Vec3& a);
	Vec3 operator*(const float a) const;
	bool operator<(const Vec3& other) const { if (x < other.x) return true; if (x > other.x) return false; if (y < other.y) return true; if (y > other.y) return false; return z < other.z; }
	bool operator>(const Vec3& other) const { if (x > other.x) return true; if (x < other.x) return false; if (y > other.y) return true; if (y < other.y) return false; return z > other.z; }
	friend Vec3	operator*(float a, Vec3 b);
	float operator * (const Vec3& a) const;
	inline Vec3 operator * (const Vec3& v) { return Vec3(x * v.x, y * v.y, z * v.z); }
	inline Vec3 operator + (const Vec3& v) { return Vec3(x + v.x, y + v.y, z + v.z); }
	inline Vec3 operator - (const Vec3& v) { return Vec3(x - v.x, y - v.y, z - v.z); }
	inline Vec3 operator / (const Vec3& v) { return Vec3(x / v.x, y / v.y, z / v.z); }
	inline Vec3 operator / (const int divisor) { return Vec3(x / divisor, y / divisor, z / divisor); }
	inline bool operator == (const Vec3& v) const { return x == v.x && y == v.y && z == v.z; }
	inline bool operator != (const Vec3& v) const { return x != v.x || y != v.y || z != v.z; }
	inline Vec3& operator += (const Vec3& v) { this->x += v.x; this->y += v.y; this->z += v.z; return *this; }
	inline Vec3& operator -= (const Vec3& v) { this->x -= v.x; this->y -= v.y; this->z -= v.z; return *this; }
	inline Vec3& operator *= (const Vec3& v) { this->x *= v.x; this->y *= v.y; this->z *= v.z; return *this; }
	inline Vec3& operator /= (const Vec3& v) { this->x /= v.x; this->y /= v.y; this->z /= v.z; return *this; }
	inline Vec3& operator/=(const float& scalar) { this->x /= scalar; this->y /= scalar; this->z /= scalar; return *this; }
	inline Vec3& operator*=(const float& scalar) { this->x *= scalar; this->y *= scalar; this->z *= scalar; return *this; }
	inline float length() const { return sqrt((x * x) + (y * y) + (z * z)); }
	inline float Length2D() const { return sqrt((x * x) + (y * y)); }
	inline float Length2DRounded() const { return sqrt((roundf(x) * x) + (roundf(y) * y)); }
	inline float DotProduct(const Vec3 v) const { return (x * v.x + y * v.y + z * v.z); }
	inline Vec3 Rounded() const { return Vec3(roundf(this->x), roundf(this->y), roundf(this->z)); }
	inline float Dist(const Vec3& v) { return (*this - v).length(); }
	inline float Dist2D(const Vec3& other) const { return sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y)); }
	inline float DistVec2_2D(const Vec2 v) { return (Vec2(x, y) - Vec2(v.x, v.y)).Length(); }
	inline Vec3 getFractional() { float whole; return { std::modf(x, &whole), std::modf(y, &whole),std::modf(z, &whole) }; }
	inline Vec3 getFractionalAbs() { float whole; return { fabs(std::modf(x, &whole)), fabs(std::modf(y, &whole)), fabs(std::modf(z, &whole)) }; }
	inline Vec3 normalize360() const { return Vec3(fmodf(this->x + 360.0f, 360.0f), fmodf(this->y + 360.0f, 360.0f), fmodf(this->z + 360.0f, 360.0f)); }
	inline Vec3 normalize180() const { return Vec3(fmodf(this->x + 180.0f, 180.0f), fmodf(this->y + 180.0f, 180.0f), fmodf(this->z + 180.0f, 180.0f)); }
	inline float distanceToSquared(const Vec3& other) const { return (other.x - this->x) * (other.x - this->x) + (other.y - this->y) * (other.y - this->y) + (other.z - this->z) * (other.z - this->z); }
	inline float distanceToSquared_2D(const Vec3& other) const { return (other.x - this->x) * (other.x - this->x) + (other.y - this->y) * (other.y - this->y); }
	inline Vec3 cross(const Vec3 other) { return Vec3(this->y * other.z - this->z * other.y, this->z * other.x - this->x * other.z, this->x * other.y - this->y * other.x); }
	inline float lengthSquared() const { return (this->x * this->x) + (this->y * this->y) + (this->z * this->z); }
	inline Vec3 scale(float scalar) { return Vec3(this->x * scalar, this->y * scalar, this->z * scalar); }
	inline bool isNull() const { return this->x == 0 && this->y == 0 && this->z == 0; }
	inline bool isInvalid() const { return this->x == -FLT_MAX && this->y == -FLT_MAX && this->z == -FLT_MAX; }
	inline bool isAnyNull() const { return this->x == 0.0f || this->y == 0.0f || this->z == 0.0f; }
	inline void setNull() { this->x = 0; this->y = 0; this->z = 0; }
	inline Vec3 add(Vec3 other) { return Vec3(this->x + other.x, this->y + other.y, this->z + other.z); }
	inline Vec3 sub(Vec3 other) { return Vec3(this->x - other.x, this->y - other.y, this->z - other.z); }
	inline Vec3 multiply(Vec3 other) { return Vec3(this->x * other.x, this->y * other.y, this->z * other.z); }
	inline Vec3 toAbsolute() const { return Vec3(fabs(this->x), fabs(this->y), fabs(this->z)); }
	inline Vec3 mirror() { return Vec3(x * -1.0f, y * -1.0f, z * -1.0f); }
	inline float ManhattanDistance(const Vec3& other) const { return abs(other.x - x) + abs(other.y - y); }
	Vec3 normalized();
	void normalizeInPlace();
	Vec2 to2D();
	inline Vec3 mapOnto(Vec3 other) { return Vec3(x * other.x, y * other.y, z * other.z); }
	inline bool isWithinRange(float center, float errorMargin) const;
	inline Vec3 snapVector() const { return Vec3(roundf(x), roundf(y), roundf(z)); }
};