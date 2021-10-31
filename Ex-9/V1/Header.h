#pragma once

//vector<vector<double>> Transform_Object()
//{
//	vector<vector<double>> newVertices(24, vector<double>(3, 0));
//
//	for (int i = 0; i < 24; i++) {
//		vector<double> curpoint(4, 0), matProduct(4, 0);
//		curpoint[0] = vertices[i][0];
//		curpoint[1] = vertices[i][1];
//		curpoint[2] = vertices[i][2];
//		curpoint[3] = 1;
//
//		for (int j = 0; j < 4; j++) {
//			for (int k = 0; k < 4; k++) {
//				matProduct[j] += Transformation[j][k] * curpoint[k];
//			}
//		}
//		newVertices[i][0] = round(matProduct[0]);
//		newVertices[i][1] = round(matProduct[1]);
//		newVertices[i][2] = round(matProduct[2]);
//	}
//	return newVertices;
//}

void menu_driven()
{
	vector<vector<double>> new_vertices(24, vector<double>(3, 0));
	char sub_opt;
	switch (option) {
	case 1: {
		
		//draw_3D_Object(new_vertices);
		break;
	}
	case 2: {
		
		//draw_3D_Object(new_vertices);
		break;
	}
	default: cout << "\n\n\t\t\tINVALID INPUT!!";
	}
}

//Set the vertices of the 3D object

void draw_3D_Object(vector<vector<double>> temp) {
	vector<vector<double>> color(3, vector<double>(3, 0));

	
}

//Transformations - Built-in functions- only for reference

void disp()
{
	glRotatef(45, 1, 0, 0);
	glRotatef(45, 0, 1, 0);
	glRotatef(0, 0, 0, 1);
}