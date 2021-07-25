#include <stdio.h>
#include <math.h>

typedef struct {
	
	float x;
	float y;
	float z;

} Point3D;

typedef struct {
	
	Point3D tl;
	Point3D tr;
	Point3D br;
	Point3D bl;

} Rectangle;

float distance(Point3D *, Point3D *);

void readPoint3D(Point3D *);
void readRectangle(Rectangle *);

void rectangleArea(Rectangle *);
void fallsWithin(Rectangle *, Rectangle *);

int main () 
{
	
	Rectangle r, r1, r2;

	readRectangle(&r);
	rectangleArea(&r);

	readRectangle(&r1);
	readRectangle(&r2);
	fallsWithin(&r1, &r2);
	

        return 0;
}

void readPoint3D(Point3D *p) {
	
	printf("x: ");	
	scanf("%f",&(p->x));
	printf("y: ");	
	scanf("%f",&(p->y));
	printf("z: ");	
	scanf("%f",&(p->z));
}

void readRectangle(Rectangle *r) {
	
	Point3D tl, tr, br, bl;
	
	printf("Bottom left:\n");
	readPoint3D(&bl);
	printf("Top right:\n");
	readPoint3D(&tr);
	
	r->tl.x = bl.x;
	r->tl.y = bl.y;
	r->tl.z = tr.z;

	r->tr = tr;
	
	r->br.x = tr.x;
	r->br.y = tr.y;
	r->br.z = bl.z;
	
	r->bl = bl;
}

float distance(Point3D *a, Point3D *b) {

	float distance;

	distance = sqrt((pow((b->x-a->x),2)) + (pow((b->y-a->y),2)) + (pow((b->z-a->z),2)));

	return distance;
}

void rectangleArea(Rectangle *r) {
	
	float height;
	float width;
	float area;

	height = distance(&(r->tl), &(r->bl));
	width = distance(&(r->bl), &(r->br));

	area = height * width;

	printf("Area: %f\n", area);	
}

void fallsWithin(Rectangle *a, Rectangle *b) {

	if (((b->bl.x) > (a->bl.x)) && ((b->bl.y) > (a->bl.y)) && ((b->tr.x) < (a->tr.x)) && ((b->tr.y) < (a->tr.y))) {
		printf("Within\n");
	} else {

		printf("Isn't within\n");
	}
}
