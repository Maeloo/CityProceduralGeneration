#include "PentagoneSymbol.h"


PentagoneSymbol::PentagoneSymbol ( const Vec3<float> &a, const Vec3<float> &b, const Vec3<float> &c, const Vec3<float> &d, const Vec3<float> &e, const Vec3<float> &mid_ ) {
	p[0] = a;
	p[1] = b;
	p[2] = c;
	p[3] = d;
	p[4] = e;

	mid = mid_;
}

void PentagoneSymbol::Generate ( Mesh &mesh, int compteur ) const {
	if ( ( compteur == 0 ) || Pentagone ( p[0], p[1], p[2], p[3], p[4] ).area ( ) < 1000.f ) {
		Mesh m = Mesh::Pentagone ( p[0], p[1], p[2], p[3], p[4] );
		//m.transform ( Transform::Shrink ( .95f, m.getPivot ( ) ) );
		mesh.merge ( m );
		//Bloc( p[0], p[1], p[2] ).G(mesh);
	}
	else {
		int random = rand ( ) % 100;

		if ( random < 50 ) {
			// Divise le pentagone en 5 triangles
			Vec3<float> pivot ( .0f );
			for ( unsigned int i = 0; i < 5; ++i ) {
				pivot += p[i];
			}
			pivot = pivot / 5.f;

			/*TriangleSymbol ( p[0], pivot, p[1], mid ).Generate ( mesh, compteur - 1 );
			TriangleSymbol ( p[2], pivot, p[3], mid ).Generate ( mesh, compteur - 1 );
			TriangleSymbol ( p[3], pivot, p[4], mid ).Generate ( mesh, compteur - 1 );
			TriangleSymbol ( p[4], pivot, p[0], mid ).Generate ( mesh, compteur - 1 );
			TriangleSymbol ( p[1], pivot, p[2], mid ).Generate ( mesh, compteur - 1 );*/
		}
		else {
			// Divise le pentagone en 1 triangle et 1 quadrangle
			Vec3<float>
				A = p[0],
				B = p[1],
				C = p[2],
				D = p[3],
				E = p[4];
			
			float a = Triangle ( A, B, C ).area ( );
			float b = Triangle ( B, C, D ).area ( );
			float c = Triangle ( C, D, E ).area ( );
			float d = Triangle ( D, E, A ).area ( );
			float e = Triangle ( E, A, B ).area ( );

			if ( a > b && a > c && a > d && a > e ) {
				/*TriangleSymbol ( A, B, C, mid ).Generate ( mesh, compteur - 1 );
				QuadrangleSymbol ( A, C, D, E, mid ).Generate ( mesh, compteur - 1 );*/
			}

			if ( b > c && b > d && b > e && b > a ) {
				/*TriangleSymbol ( B, C, D, mid ).Generate ( mesh, compteur - 1 );
				QuadrangleSymbol ( B, D, E, A, mid ).Generate ( mesh, compteur - 1 );*/
			}

			if ( c > d && c > e && c > a && c > b ) {
				/*TriangleSymbol ( C, D, E, mid ).Generate ( mesh, compteur - 1 );
				QuadrangleSymbol ( C, E, A, B, mid ).Generate ( mesh, compteur - 1 );*/
			}

			if ( d > e && d > a && d > b && d > c ) {
				/*TriangleSymbol ( D, E, A, mid ).Generate ( mesh, compteur - 1 );
				QuadrangleSymbol ( D, A, B, C, mid ).Generate ( mesh, compteur - 1 );*/
			}

			if ( e > a && e > b && e > c && e > d ) {
				/*TriangleSymbol ( E, A, B, mid ).Generate ( mesh, compteur - 1 );
				QuadrangleSymbol ( E, B, C, D, mid ).Generate ( mesh, compteur - 1 );*/
			}
		}
	}
}

