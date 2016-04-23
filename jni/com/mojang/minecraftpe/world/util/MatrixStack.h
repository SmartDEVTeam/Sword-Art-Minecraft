#pragma once

class Vec3;

class Matrix {
public:
	void translate(const Vec3&);
	void scale(const Vec3&);
   void invert();
   void rotate(float, Vec3 const&);
};

class MatrixStack {
public:

	class Ref {
	public:
		MatrixStack* stack;
		Matrix* matrix;
	};


	static MatrixStack Projection;
   static MatrixStack World;
   static MatrixStack View;

	MatrixStack::Ref push();
	void pop();
};
