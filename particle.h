#ifndef _PARTICLE_H_
#define _PARTICLE_H_

# include "vector.h"

class Particle {
	public:

		double m; // mass
		vector pos; // position
		vector v; // velocity
		vector F; // force on particle

		void render();
};



#endif
