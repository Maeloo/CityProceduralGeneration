#include "Vec3.h"
#include "MeshWriter.h"
#include "Transform\Transform.h"
#include "Geometry\Quadrangle.h"
#include "Geometry\Triangle.h"
#include "Geometry\Hexagone.h"
#include "Mesh\Mesh.h"

#include "Grammar\Map\PentagoneSymbol.h"
#include "Grammar\Map\QuadrangleSymbol.h"
#include "Grammar\Map\TriangleSymbol.h"
#include "Grammar\BatimentQuadra\RDC.h"

#include "Utils.h"
#include<chrono>
#include <iostream>
#include <fstream>
int main(int argc, char ** argv)
{
	srand(time(NULL));
	std::ofstream mesureFile("mesureFile.txt", std::ios::out | std::ios::trunc);
	auto start = std::chrono::high_resolution_clock::now();
	auto end = std::chrono::high_resolution_clock::now();



	//QuadrangleSymbol qs = QuadrangleSymbol::genBorder(Vec3<float>(0.f), Vec3<float>(0.f, 500.f, 0.f), Vec3<float>(500.f, 500.f, 0.f), Vec3<float>(500.f, 0.f, 0.f), 10.f, 3.f, 1.f, m,Vec3<float>(250.f,250.f,0.f));
	////m.merge(Mesh::RouteL(Vec3<float>(100.f, 100.f, 0.f), Vec3<float>(100.f, 0.f, 0.f), Vec3<float>(110.f, 0.f, 0.f), Vec3<float>(10.f, 150.f, 0.f), 1.f, 1.f));
	//qs.Generate(m, 10);
	//MeshWriter::exportObj(m, "testSymbole.obj");
	
	start = std::chrono::high_resolution_clock::now();
	Mesh m;
	QuadrangleSymbol qs = QuadrangleSymbol::genBorder(Vec3<float>(0.f), Vec3<float>(0.f, 500.f, 0.f), Vec3<float>(500.f, 500.f, 0.f), Vec3<float>(500.f, 0.f, 0.f), 10.f, 3.f, 1.f, m, Vec3<float>(250.f, 250.f, 0.f), Vec3<float>(500.f, 500.f, 0.f));
	qs.Generate(m, 10);
	end = std::chrono::high_resolution_clock::now();
	mesureFile << "Generation terrain : " << std::chrono::duration<float, std::milli>(end - start).count() << " ms" << std::endl;
	start = std::chrono::high_resolution_clock::now();
	MeshWriter::exportObj(m, "testSymbole.obj"); 
	end = std::chrono::high_resolution_clock::now();
	mesureFile << "ecriture obj : " << std::chrono::duration<float, std::milli>(end - start).count() << " ms" << std::endl;
	
	
	
	
	mesureFile.close();



	//Mesh m;//(Mesh::Quadrangle(Vec3<float>(0.f), Vec3<float>(0.f, 150.f, 0.f), Vec3<float>(100.f, 100.f, 0.f), Vec3<float>(100.f, 0.f, 0.f)));
	//QuadrangleSymbol qs(Vec3<float>(0.f), Vec3<float>(0.f, 150.f, 0.f), Vec3<float>(100.f, 100.f, 0.f), Vec3<float>(100.f, 0.f, 0.f));
	//qs.Generate(m, 3);
	//MeshWriter::exportObj(m, "testSymbole.obj");
	/*Vec3<float> _Points[6]= {Vec3<float>(0.f),Vec3<float>(5.f,5.f,0.f),Vec3<float>(10.f,5.f,0.f),Vec3<float>(15.f,0.f,0.f),Vec3<float>(10.f,-5.f,0.f),Vec3<float>(5.f,-5.f,0.f)};
	Hexagone q(_Points);

	std::cout<<"Aire : "<<q.area()<<" et Premietre : "<<q.perimeter()<<"\n"<<std::endl;*/

	/************************ Example Pentagone Mesh *****************************/

	//Mesh m(Mesh::Pentagone(Vec3<float>(0.f), Vec3<float>(5.f, 5.f, 0.f), Vec3<float>(10.f, 5.f, 0.f), Vec3<float>(15.f, 0.f, 0.f), Vec3<float>(10.f, -5.f, 0.f)));
	//MeshWriter::exportObj ( m, "test_pentagone.obj" );

	/************************ Example Hexagone Mesh *****************************/
	/*std::vector<Vec3<float>> points = { Vec3<float> ( 0.f ), Vec3<float> ( 5.f, 5.f, 0.f ), Vec3<float> ( 10.f, 5.f, 0.f ), Vec3<float> ( 15.f, 0.f, 0.f ), Vec3<float> ( 10.f, -5.f, 0.f ), Vec3<float> ( 5.f, -5.f, 0.f ) };
	HexagoneMesh hm = HexagoneMesh ( points );
	Mesh m ( hm );
	MeshWriter::exportObj ( m, "test_hexagone.obj" );*/

	/************************ Example TriangleSymbol Generate *****************************/
	//std::vector<Vec3<float>> points = { Vec3<float> ( -200.f, -200.f, 0.f ), Vec3<float> ( 200, -200.f, 0.f ), Vec3<float> ( 0, 200, 0.f ) };
	//Mesh m2;
	//TriangleSymbol ts = TriangleSymbol::genBorder ( points[0], points[1], points[2], 10.f, 3.f, 1.f, m2, Vec3<float> ( 0.f ), Vec3<float> ( 250.f, 250.f, 0.f ) );
	//ts.Generate ( m2, 10 );

	//MeshWriter::exportObj ( m2, "test_triangle_symbole2.obj" );
	/************************ Example PentagoneSymbol Generate *****************************/
	//std::vector<Vec3<float>> points = { Vec3<float> ( 0.f ), Vec3<float> ( 0.f, 1500.f, 0.f ), Vec3<float> ( 1000.f, 1000.f, 0.f ), Vec3<float> ( 1000.f, 0.f, 0.f ), Vec3<float> ( 500.f, -600.f, 0.f ) };
	//Mesh m2;
	//PentagoneSymbol ps = PentagoneSymbol ( points[0], points[1], points[2], points[3], points[4] );
	//ps.Generate ( m2, 3 );

	////m2 = Mesh::Pentagone ( points[0], points[1], points[2], points[3], points[4] );

	//MeshWriter::exportObj ( m2, "test_pentagone_symbol.obj" );

	/************************ Example shrink triangle *****************************/
	/*std::vector<Vec3<float>> points = { Vec3<float> ( 0.f ), Vec3<float> ( 10.f, 0.f, 0.f ), Vec3<float> ( 10.f, 10.f, 0.f ) };
	Mesh m1, m2;
	Triangle t ( Vec3<float> ( 0.f ), Vec3<float> ( 10.f, 0.f, 0.f ), Vec3<float> ( 10.f, 10.f, 0.f ) );
	t.shrinkByDist ( 1.0f );
	Vec3<float> *points2 = t.getPoints ( );
	TriangleSymbol ts1 = TriangleSymbol ( points[0], points[1], points[2], Vec3<float> ( .0f ) );
	TriangleSymbol ts2 = TriangleSymbol ( points2[0], points2[1], points2[2], Vec3<float> ( .0f ) );

	ts1.Generate ( m1, 0 );
	ts2.Generate ( m2, 0 );

	m1.transform ( Transform::translate ( Vec3<float> ( 0.f, 0.f, -5.f ) ) );

	m1.merge ( m2 );

	MeshWriter::exportObj ( m1, "test_shrink_dist.obj" );
*/
	/************************ Example shrink quadrangle *****************************/
	/*std::vector<Vec3<float>> points = { Vec3<float> ( 0.f ), Vec3<float> ( 0.f, 150.f, 0.f ), Vec3<float> ( 100.f, 100.f, 0.f ), Vec3<float> ( 100.f, 0.f, 0.f ) };
	Mesh m1, m2;
	Quadrangle q ( points[0], points[1], points[2], points[3] );
	q.shrinkByDist ( 10.f );
	m1 = Mesh::Quadrangle ( points[0], points[1], points[2], points[3] );
	m2 = Mesh::Quadrangle ( q.p1, q.p2, q.p3, q.p4 );

	m1.transform ( Transform::translate ( Vec3<float> ( 0.f, 0.f, -5.f ) ) );

	m1.merge ( m2 );

	MeshWriter::exportObj ( m1, "test_shrink_dist2.obj" );*/


	//Mesh m = Mesh::Arbre(Vec3<float>(0.f),10);
	//MeshWriter::exportObj ( m, "Cone.obj" );

	/************************  *****************************/
	//Mesh m;
	//RDC(Vec3<float>(0.f), Vec3<float>(0.f, 150.f, 0.f), Vec3<float>(100.f, 100.f, 0.f), Vec3<float>(100.f, 0.f, 0.f), 10.f).G(m);
	//MeshWriter::exportObj ( m, "test_batiment.obj" );

	/*Mesh m;
	RDC(Vec3<float>(0.f), Vec3<float>(0.f, 100.f, 0.f), Vec3<float>(150.f, 100.f, 0.f), Vec3<float>(170.f, 0.f, 0.f), 10.f,100.f,0).G(m);
	MeshWriter::exportObj ( m, "test_batiment.obj" );*/

	//MeshWriter::exportObj(Mesh::Route(Vec3<float>(0.f), Vec3<float>(0.f, 150.f, 0.f), Vec3<float>(100.f, 100.f, 0.f), Vec3<float>(100.f, 0.f, 0.f), 20.f), "test_route.obj");



	// ****************** test decoupe en quartier ***********
	/*Mesh m;
	QuadrangleSymbol qs = QuadrangleSymbol::genBorder(Vec3<float>(0.f), Vec3<float>(0.f, 500.f, 0.f), Vec3<float>(500.f, 500.f, 0.f), Vec3<float>(500.f, 0.f, 0.f), 10.f, 3.f, 1.f, m, Vec3<float>(250.f, 250.f, 0.f), Vec3<float>(500.f, 500.f, 0.f));
	QuadrangleSymbol qs = QuadrangleSymbol::genBorder(Vec3<float>(0.f), Vec3<float>(0.f, 100.f, 0.f), Vec3<float>(100.f, 100.f, 0.f), Vec3<float>(100.f, 0.f, 0.f), 10.f, 3.f, 1.f, m, Vec3<float>(50.f, 50.f, 0.f));
	qs.Generate(m, 1);
	MeshWriter::exportObj(m, "testQuartier.obj");*/

	// ****************** test collision segment segment ****** 
	/*Utils::isSegmentIntersect(1, 1, 10, 1, 1, 2, 10, 2) ? std::cout << "Yes\n" : std::cout << "No\n";
	Utils::isSegmentIntersect(10, 10, 0, 10, 0, 0, 10, 10) ? std::cout << "Yes\n" : std::cout << "No\n";
	Utils::isSegmentIntersect(-5, -5, 0, 0, 1, 1, 10, 10) ? std::cout << "Yes\n" : std::cout << "No\n";*/

	//****************** test quad quad intersections ****** 
	/*Quadrangle(Vec3<float>(0.F, 0.f, 0.f), Vec3<float>(10.F, 0.f, 0.f), Vec3<float>(10.F, 10.f, 0.f), Vec3<float>(0.F, 10.f, 0.f))
		.intersect(Quadrangle(Vec3<float>(0.f, 0.f, 0.f), Vec3<float>(5.f, 0.f, 0.f), Vec3<float>(5.f, 5.f, 0.f), Vec3<float>(0.F, 5.F, 0.f))) ?
		std::cout << "Yes\n" : std::cout << "No\n";

	Quadrangle(Vec3<float>(0.F, 0.f, 0.f), Vec3<float>(10.F, 0.f, 0.f), Vec3<float>(10.F, 10.f, 0.f), Vec3<float>(0.F, 10.f, 0.f))
		.intersect(Quadrangle(Vec3<float>(0.f, 11.f, 0.f), Vec3<float>(11.f, 11.f, 0.f), Vec3<float>(11.f, 22.f, 0.f), Vec3<float>(0, 22.F, 0.f))) ?
		std::cout << "Yes\n" : std::cout << "No\n";

	Quadrangle(Vec3<float>(0.F, 0.f, 0.f), Vec3<float>(10.F, 0.f, 0.f), Vec3<float>(10.F, 10.f, 0.f), Vec3<float>(0.F, 10.f, 0.f))
		.intersect(Quadrangle(Vec3<float>(1.f, 1.f, 0.f), Vec3<float>(5.f, 1.f, 0.f), Vec3<float>(5.f, 5.f, 0.f), Vec3<float>(1.F, 5.F, 0.f))) ?
		std::cout << "Yes\n" : std::cout << "No\n";

	Quadrangle(Vec3<float>(0.F, 0.f, 0.f), Vec3<float>(10.F, 0.f, 0.f), Vec3<float>(10.F, 10.f, 0.f), Vec3<float>(0.F, 10.f, 0.f))
		.isIn(Quadrangle(Vec3<float>(1.f, 1.f, 0.f), Vec3<float>(5.f, 1.f, 0.f), Vec3<float>(5.f, 5.f, 0.f), Vec3<float>(1.F, 5.F, 0.f))) ?
		std::cout << "Yes\n" : std::cout << "No\n";

	Quadrangle(Vec3<float>(0.F, 0.f, 0.f), Vec3<float>(10.F, 0.f, 0.f), Vec3<float>(10.F, 10.f, 0.f), Vec3<float>(0.F, 10.f, 0.f))
		.isIn(Quadrangle(Vec3<float>(0.f, 11.f, 0.f), Vec3<float>(11.f, 11.f, 0.f), Vec3<float>(11.f, 22.f, 0.f), Vec3<float>(0, 22.F, 0.f))) ?
		std::cout << "Yes\n" : std::cout << "No\n";

	Quadrangle(Vec3<float>(0.F, 0.f, 0.f), Vec3<float>(10.F, 0.f, 0.f), Vec3<float>(10.F, 10.f, 0.f), Vec3<float>(0.F, 10.f, 0.f))
		.isIn(Quadrangle(Vec3<float>(1.f, 1.f, 0.f), Vec3<float>(5.f, 1.f, 0.f), Vec3<float>(5.f, 5.f, 0.f), Vec3<float>(1.F, 5.F, 0.f))) ?
		std::cout << "Yes\n" : std::cout << "No\n";

	Quadrangle(Vec3<float>(0.F, 0.f, 0.f), Vec3<float>(10.F, 0.f, 0.f), Vec3<float>(10.F, 10.f, 0.f), Vec3<float>(0.F, 10.f, 0.f))
		.overlap(Quadrangle(Vec3<float>(0.f, 0.f, 0.f), Vec3<float>(5.f, 0.f, 0.f), Vec3<float>(5.f, 5.f, 0.f), Vec3<float>(0.F, 5.F, 0.f))) ?
		std::cout << "Yes\n" : std::cout << "No\n";

	Quadrangle(Vec3<float>(0.F, 0.f, 0.f), Vec3<float>(10.F, 0.f, 0.f), Vec3<float>(10.F, 10.f, 0.f), Vec3<float>(0.F, 10.f, 0.f))
		.overlap(Quadrangle(Vec3<float>(0.f, 11.f, 0.f), Vec3<float>(11.f, 11.f, 0.f), Vec3<float>(11.f, 22.f, 0.f), Vec3<float>(0, 22.F, 0.f))) ?
		std::cout << "Yes\n" : std::cout << "No\n";

	Quadrangle(Vec3<float>(0.F, 0.f, 0.f), Vec3<float>(10.F, 0.f, 0.f), Vec3<float>(10.F, 10.f, 0.f), Vec3<float>(0.F, 10.f, 0.f))
		.overlap(Quadrangle(Vec3<float>(1.f, 1.f, 0.f), Vec3<float>(5.f, 1.f, 0.f), Vec3<float>(5.f, 5.f, 0.f), Vec3<float>(1.F, 5.F, 0.f))) ?
		std::cout << "Yes\n" : std::cout << "No\n";*/

	system("pause");
	return 0;
}