#include <stdio.h>
#include <math.h>

#define num 10

typedef struct {
	
	float x;
	float y;
	float z;

} Point3D;

void readPoint3D(Point3D *);

float distance(Point3D *, Point3D *);

void nearestPoint(Point3D[], Point3D *, Point3D *);
void farthestPoint(Point3D[], Point3D *, Point3D *);

int main() 
{
	
	Point3D points[num];

	Point3D nearest1, nearest2, farthest1, farthest2;

	for (int i=0; i<num; i++) {
		
		readPoint3D(&(points[i]));
	}
	
	nearestPoint(points, &nearest1, &nearest2);
	farthestPoint(points, &farthest1, &farthest2);

	printf("Nearest Points: (%f, %f, %f) AND (%f, %f, %f)\n", nearest1.x, nearest1.y, nearest1.z, nearest2.x, nearest2.y, nearest2.z);
	printf("Farthest Points: (%f, %f, %f) AND (%f, %f, %f)\n", farthest1.x, farthest1.y, farthest1.z, farthest2.x, farthest2.y, farthest2.z);  

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

float distance(Point3D *a, Point3D *b) {

	float distance;

	distance = sqrt((pow((b->x-a->x),2)) + (pow((b->y-a->y),2)) + (pow((b->z-a->z),2)));

	return distance;
}

void nearestPoint(Point3D arrayOfPoints[], Point3D *a, Point3D *b) {
	
	float shortestDistance = distance(&arrayOfPoints[0], &arrayOfPoints[1]);

	a->x = arrayOfPoints[0].x;
	a->y = arrayOfPoints[0].y;
	a->z = arrayOfPoints[0].z;

	b->x = arrayOfPoints[1].x;
	b->y = arrayOfPoints[1].y;
	b->z = arrayOfPoints[1].z;

	float distanceTmp;
	
	for (int i=0; i < num; i++) {
		
		for (int j=i+1; j < num; j++) {

			distanceTmp = distance(&arrayOfPoints[i], &arrayOfPoints[j]);

			if (distanceTmp < shortestDistance) {

				shortestDistance = distanceTmp;
				
				a->x = arrayOfPoints[i].x;
				a->y = arrayOfPoints[i].y;
				a->z = arrayOfPoints[i].z;
				
				b->x = arrayOfPoints[j].x;
				b->y = arrayOfPoints[j].y;
				b->z = arrayOfPoints[j].z;
				
			}
		}
	}
}

void farthestPoint(Point3D arrayOfPoints[], Point3D *a, Point3D *b) {
	
	float farthestDistance = distance(&arrayOfPoints[0], &arrayOfPoints[1]);

	a->x = arrayOfPoints[0].x;
	a->y = arrayOfPoints[0].y;
	a->z = arrayOfPoints[0].z;

	b->x = arrayOfPoints[1].x;
	b->y = arrayOfPoints[1].y;
	b->z = arrayOfPoints[1].z;

	float distanceTmp;
	
	for (int i=0; i < num; i++) {
		
		for (int j=i+1; j < num; j++) {

			distanceTmp = distance(&arrayOfPoints[i], &arrayOfPoints[j]);

			if (distanceTmp > farthestDistance) {

				farthestDistance = distanceTmp;
				
				a->x = arrayOfPoints[i].x;
				a->y = arrayOfPoints[i].y;
				a->z = arrayOfPoints[i].z;
				
				b->x = arrayOfPoints[j].x;
				b->y = arrayOfPoints[j].y;
				b->z = arrayOfPoints[j].z;
				
			}
		}
	}	
}

