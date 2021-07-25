#include <stdio.h>

typedef struct {
	
	int hh;
	int mm;
	double seconds;
} Time;

void lerTime(Time*);
Time convertTime(double);
Time addTime(Time*, Time*);

int main() 
{

	Time a, b, converted, soma;
	double secs;

	printf("Segundos: ");
	scanf("%lf", &secs);

	converted = convertTime(secs);

	printf("Horas: %d\nMinutos: %d\nSegundos: %lf\n", converted.hh, converted.mm, converted.seconds);

	lerTime(&a);
	lerTime(&b);

	soma = addTime(&a, &b);

	printf("Horas: %d\nMinutos: %d\nSegundos: %lf\n", soma.hh, soma.mm, soma.seconds);

        return 0;
}

void lerTime(Time* t) {

	int hh, mm;
	double secs;

	printf("Horas: ");
	scanf("%d", &hh);
	printf("Minutos: ");
	scanf("%d", &mm);
	printf("Segundos: ");
	scanf("%lf", &secs);

	t->hh = hh;
	t->mm = mm;
	t->seconds = secs;
}

Time convertTime(double secs) {
	
	Time t;

	int sec, min, hour;
	
	sec = (int)secs % 60;
	min = (int)secs / 60;
	
	if (min >= 60) {
		min = min % 60;
	}
	
	hour = (int)(secs / 3600);

	t.seconds = sec;
	t.mm = min;
	t.hh = hour;

	return t;
}

Time addTime(Time* a, Time* b) {
	
	Time t;
	
	int secs1, secs2, mins, mins1, mins2, hours;

	secs1 = (((int)(a->seconds) + (int)(b->seconds)) % 60);
	secs2 = (((int)(a->seconds) + (int)(b->seconds)) / 60);

	t.seconds = secs1;

	mins1 = ((a->mm + b->mm) % 60);
	mins2 = ((a->mm + b->mm) / 60);

	mins = mins1 + secs2;

	if (mins >= 60) {
		mins = mins % 60;
		mins2++;
	}

	t.mm = mins;
	
	t.hh = a->hh + b->hh + mins2;

	return t;	
}

