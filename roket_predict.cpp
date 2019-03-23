#include <iostream>
#include <cmath>

constexpr double dT = 1e-4;

struct Vector {
	double x;
	double y;
};

Vector add(Vector v1, Vector v2) {
  Vector v;
  v.x = v1.x + v2.x;
  v.y = v1.y + v2.y;
  
  return v;
}

Vector sub(Vector v1, Vector v2) {
	Vector v;
	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;

	return v;
}

Vector mul(Vector v, double k) {
	Vector w;
	w.x = v.x * k;
	w.y = v.y * k;

	return w;
}

// k dalam radian berlawanan arah jarum jam
Vector rot(Vector v, double k) {
	Vector w;
	w.x = std::cos(k)*v.x - std::sin(k)*v.y;
	w.y = std::sin(k)*v.x + std::cos(k)*v.y;

	return w;
}

// melakukan simulasi
Vector calc(Vector v, double w, double aM, double t) {
	Vector r;
	r.x = 0;
	r.y = 0;
	Vector a;
	a.x = aM;
	a.y = 0;
	for (double t1 = 0; t1 < t; t1 += dT) {
	r = add(r, mul(v, dT));
	v = add(v, mul(a,dT));
	a = rot(a, w*dT);
	}
	return r;
}

int main() {
	Vector v,r,rt, res;
	double w, aM, t;
	r.x=0;
	r.y=0;
	v.x=0;
	v.y=0;
	aM=5;
	w=1;
    std::cin >> rt.x >> rt.y >> t;
	d = sqrt(rt.x*rt.x + rt.y*rt.y);
	// while (fabs(rt.x-r.x)>0.01 || fabs(rt.y-r.y)>0.01){
		// r = calc(v,w, aM,t);
		// if (rt.x>r.x){
			// aM*=1.5;
		// }else {
			// aM/=2;
		// }
		// std::cout << r.x << '*' << aM << '\n';
		// std::cout << rt.x-r.x << '#' << rt.y-r.y << '\n';
	// }
	while (fabs(r.x-d)>0.01 && (fabs(r.x)<fabs(d))){
		if (r.x > d){
			aM-=0.01;
		}else{
			aM+=0.01;
		}
		r = calc(v,w,aM,t);
		// std::cout << r.x << '*' << rt.x << '\n';		
	}
	while (fabs(r.y-rt.y)>0.01 && (fabs(r.y)<fabs(rt.y))){
		if (r.y > rt.y){
			w-=0.01;
		}else{
			w+=0.01;
		}
		r = calc(v,w,aM,t);
		// if (r.y < temp){
			// aM+=0.01;
			// r = calc(v,w,aM,t);
		// }else{
			// temp = r.y;
		// }
		// std::cout << r.y << '&' << w << '\n';
	}
	res = calc(v,w,aM,t);
	std::cout << w << ' ' << aM << '\n';
	// std::cout << res.x << "    " << res.y << '\n';
	
	std::cin >> w;
}