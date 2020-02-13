#ifndef UTILITY_H
#define UTILITY_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Utility
{

public:
	static Vector2f normalize(const Vector2f& vec);
	static float magnitude(const Vector2f& vec);

	static float angle(const Vector2f& vec);
	static float angleBetween(const Vector2f& vec1, const Vector2f& vec2);

	static Vector2f rotatePoint(const Vector2f& vec, float angleR);

	
	static Vector2f movePoint(const Vector2f& vec, float angleR, float distance);


	/*
		Point limit in the range [vec.x , vec.y]
		- return Vector2f
	*/
	static void clampPoint(Vector2f& vec, const Vector2f& vec_limit);

	/*
		Value limit in the range [min , max]
		- return float
	*/
	static float clamp(float& val, float min, float max);

	static bool isZero(const Vector2f& vec);

	/*
		Find dot product
		- return float
	*/
	static float dotProduct(const Vector2f& vec1, const Vector2f& vec2);

	static float determinant(const Vector2f& vec1, const Vector2f& vec2);

	/*
		To find orientation of ordered triplet (p, q, r).
		- return 0 They colinear
		- return 1 They are all clockwise
		- return 2 Thay are counter clockwise
	*/
	static int orientation(const Vector2f& p, const Vector2f& q, const Vector2f& r);

	/*
		Check two segment intersection
		- return true : intersect
		- return fale : not intersect
	*/
	static bool checkSegmentIntersection(const Vector2f& v1, const Vector2f& v2, const Vector2f& u1, const Vector2f& u2);

	/*
		Get point two segment intersection
		- return Vector2f point
	*/
	static Vector2f getSegmentIntersection(const Vector2f& v1, const Vector2f& v2, const Vector2f& u1, const Vector2f& u2);

	/*
		Check two vetor same direction
		- return true : if the same
		- return flase : then
	*/
	static bool checkSameDirection(const Vector2f& v1, const Vector2f& v2);

	/*
		Draw line used VertexArray
		- return graphic : draw line two point
	*/
	static void drawLine(const Vector2f& v1, const Vector2f& v2, RenderWindow& window, Color color = Color::White);

	/*
		Mapping value from source to destination ranges [a-b] -> [c-d]
		- return float : x => [c-d]
	*/
	static float map(const float value, const Vector2f rang_src, const Vector2f rang_dist);
};


#endif // !UTILITY_H


