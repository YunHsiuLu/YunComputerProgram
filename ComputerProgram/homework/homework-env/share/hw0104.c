#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct Pokemon {
	int level;
	int atk;
	int def;
	int power;
	int cate;
	int type;
	int m_type;
	int status;
	float factor;
	int damage;
};

struct Env {
	int weather;
	int terrain;
};

int main() {
	srand(time(NULL));
	struct Pokemon attacker, target;
	struct Env env;
	
	env.weather = rand()%6;
	env.terrain = rand()%4;
	
	attacker.level = rand()%101;
	attacker.atk = rand()%500;
	attacker.type = rand()%8;
	attacker.m_type = rand()%8;
	attacker.status = rand()%3;
	attacker.power = rand()%500;
	attacker.cate = rand()%2;
	attacker.factor = 1.;

	// special type
	if (env.weather == 5 && target.type == 4)
		target.def *= 2;
	else if (env.weather == 2 && target.type ==5)
		target.def /= 2;
	else if (env.weather == 3 && attacker.type == 2)
		attacker.atk /= 2;
	else if (env.weather == 4 && attacker.type == 3)
		attacker.atk *= 2;
	else
		attacker.factor *= 1.;

	// weather
	if ((env.weather == 1 && attacker.type == 0)||(env.weather == 2 && attacker.type == 1))
		attacker.factor *= 0.5;
	else if ((env.weather == 1 && attacker.type == 1)||(env.weather == 2 && attacker.type == 0))
		attacker.factor *= 2.;
	else attacker.factor *= 1.;

	// stab: same type attacker bonus
	if (attacker.type == attacker.m_type)
		attacker.factor *= 2.;
	else attacker.factor *= 1.;
	
	target.def = rand()%200;
	target.type = rand()%8;

	// type effect
	if (attacker.type == 0) {
		if (target.type == 0 || target.type == 2 || target.type == 7)
			attacker.factor *= 0.5;
		else if (target.type == 1 || target.type == 5 || target.type == 6)
			attacker.factor *= 2.;
		else
			attacker.factor *= 1.;
	}
	else if (attacker.type == 1) {
		if (target.type == 0 || target.type == 1 || target.type == 4 || target.type == 7)
			attacker.factor *= 0.5;
		else if (target.type == 2)
			attacker.factor *= 2.;
		else
			attacker.factor *= 1.;
	}
	else if (attacker.type == 2) {
		if (target.type == 1 || target.type == 2 || target.type == 3 || target.type == 7)
			attacker.factor *= 0.5;
		else if (target.type == 0 || target.type == 4 || target.type == 5)
			attacker.factor *= 2.;
		else
			attacker.factor *= 1.;
	}
	else if (attacker.type == 3) {
		if (target.type == 4 || target.type == 6)
			attacker.factor *= 0.5;
		else if (target.type == 2)
			attacker.factor *= 2.;
		else
			attacker.factor *= 1.;
	}
	else if (attacker.type == 4) {
		if (target.type == 5)
			attacker.factor *= 0.5;
		else if (target.type == 1 || target.type == 3)
			attacker.factor *= 2.;
		else
			attacker.factor *= 1.;
	}
	else if (attacker.type == 5) {
		if (target.type == 3)
			attacker.factor *= 0;
		else if (target.type == 1 || target.type == 4 || target.type == 6)
			attacker.factor *= 2.;
		else
			attacker.factor *= 1;
	}
	else if (attacker.type == 6) {
		if (target.type == 5)
			attacker.factor *= 0;
		else if (target.type == 2 || target.type == 6 || target.type == 7)
			attacker.factor *= 0.5;
		else if ( target.type == 0 || target.type == 3)
			attacker.factor *= 2.;
		else
			attacker.factor *= 1.;
	}
	else {
		if (target.type == 7)
			attacker.factor *= 2.;
		else
			attacker.factor *= 1.;
	}
	
	// status
	if ((attacker.status == 1 && attacker.cate == 0) || (attacker.status == 2 && attacker.cate == 1))
		attacker.factor *= 0.5;
	else
		attacker.factor *= 1.;
	// terrain
	if (env.terrain == 1 && attacker.type == 2)
		attacker.factor *= 2.;
	else if (env.terrain == 2 && attacker.type == 6)
		attacker.factor *= 2.;
	else if (env.terrain == 3 && attacker.type == 7)
		attacker.factor *= 0.5;
	else
		attacker.factor *= 1.;

	// compute damage
	attacker.damage = (int) floor((floor((attacker.level*2 + 10)/(float)250 * attacker.atk/(float)target.def * attacker.power) + 2) * attacker.factor);

	printf("Attacker\n");
	printf("\tlevel: %d\n", attacker.level);
	printf("\tatk: %d\n", attacker.atk);
	printf("\ttype: %d\n", attacker.type);
	printf("\tstatus: %d\n", attacker.status);
	printf("\tmove power: %d\n", attacker.power);
	printf("\tmove type: %d\n", attacker.m_type);
	printf("\tmove category: %d\n", attacker.cate);

	printf("Target\n");
	printf("\tdef: %d\n", target.def);
	printf("\ttype: %d\n", target.type);

	printf("Environment:\n");
	printf("\tweather: %d\n", env.weather);
	printf("\tterrain: %d\n", env.terrain);

	printf("Damage --> %d\n", attacker.damage);
	return 0;
}
