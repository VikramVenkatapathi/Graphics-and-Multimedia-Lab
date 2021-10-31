#pragma once

vector<vector<double>> translate()
{
	vector<vector<double>> temp(4, vector<double>(4, 0));

	temp[0][0] = 1;
	temp[1][1] = 1;
	temp[2][2] = 1;
	temp[3][3] = 1;
	temp[0][3] = tx;
	temp[1][3] = ty;
	temp[2][3] = tz;

	return temp;
}

vector<vector<double>> scale()
{
	vector<vector<double>> temp(4, vector<double>(4, 0));

	temp[0][0] = sx;
	temp[1][1] = sy;
	temp[2][2] = sz;
	temp[3][3] = 1;
	temp[0][3] = (1 - sx)*xf;
	temp[1][3] = (1 - sy)*yf;
	temp[2][3] = (1 - sz)*zf;

	return temp;
}

vector<vector<double>> rotate_X() 
{
	vector<vector<double>> temp(4, vector<double>(4, 0));

	temp[0][0] = 1;
	temp[1][1] = cos(angRad);
	temp[2][2] = cos(angRad);
	temp[3][3] = 1;
	temp[2][1] = sin(angRad);
	temp[1][2] = -1 * sin(angRad);
	
	return temp;
}

vector<vector<double>> rotate_Y()
{
	vector<vector<double>> temp(4, vector<double>(4, 0));

	temp[0][0] = cos(angRad);
	temp[1][1] = 1;
	temp[2][2] = cos(angRad);
	temp[3][3] = 1;
	temp[0][2] = sin(angRad);
	temp[2][0] = -1 * sin(angRad);
	
	return temp;
}

vector<vector<double>> rotate_Z()
{
	vector<vector<double>> temp(4, vector<double>(4, 0));

	temp[0][0] = cos(angRad);
	temp[1][1] = cos(angRad);
	temp[2][2] = 1;
	temp[3][3] = 1;
	temp[1][0] = sin(angRad);
	temp[0][1] = -1 * sin(angRad);

	return temp;
}

/* TRANSLATE the rotated object
(to prevent original and transformed 
object from juxtaposing) */

vector<vector<double>> move_rotate() 
{
	Transformation[0][3]  += 400 ;
	Transformation[1][3]  += 0;
	Transformation[2][3]  += 300;

	return Transformation;
}

vector<vector<double>> Transform_Object()
{
	vector<vector<double>> newVertices(24, vector<double>(3, 0));
	
	for (int i = 0; i < 24; i++) {
		vector<double> curpoint(4, 0), matProduct(4, 0);
		curpoint[0] = vertices[i][0];
		curpoint[1] = vertices[i][1];
		curpoint[2] = vertices[i][2];
		curpoint[3] = 1;
		
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				matProduct[j] += Transformation[j][k] *	curpoint[k];
			}
		}
		newVertices[i][0] = round(matProduct[0]);
		newVertices[i][1] = round(matProduct[1]);
		newVertices[i][2] = round(matProduct[2]);
	}
	return newVertices;
}

void menu_driven()
{
	vector<vector<double>> new_vertices(24, vector<double>(3, 0));
	char sub_opt;
	switch (option) {
		case 1: {
			cout << "\n\n\t\tTranslation factors ( tx ty tz ) : ";
			cin >> tx >> ty >> tz;
			Transformation = translate();
			new_vertices = Transform_Object();
			draw_3D_Object(new_vertices,1);
			break;
		}
		case 2: {
			cout << "\n\n\t\tAngle of rotation : ";
			cin >> ang;
			angRad = ang * PI / 180;
			
			cout << "\n\n\t\tRotate about : ";
			cout << "\n\n\t\t\ta) X-axis ";
			cout << "\n\n\t\t\tb) Y-axis ";
			cout << "\n\n\t\t\tc) Z-axis -> ";
			cin >> sub_opt;
			if (sub_opt == 'a')	Transformation = rotate_X();
			else if (sub_opt == 'b')	Transformation = rotate_Y();
			else if (sub_opt == 'c')	Transformation = rotate_Z();
			else cout << "\n\n\t\t\tINVALID INPUT!!";
			Transformation = move_rotate();
			new_vertices = Transform_Object();
			draw_3D_Object(new_vertices,1);
			break;
		}
		case 3: {
			cout << "\n\n\t\tScaling factors ( sx sy sz ) : ";
			cin >> sx >> sy >> sz;
			cout << "\n\t\tScale about : ";
			cin >> xf >> yf >>zf;
			Transformation = scale();
			new_vertices = Transform_Object();
			draw_3D_Object(new_vertices,1);
			break;
		}
		default: cout << "\n\n\t\t\tINVALID INPUT!!";
	}
}

//Set the vertices of the 3D object
vector<vector<double>> set_Vertices() {

	vector<vector<double>> vertices(24, vector<double>(3, 0));

	vertices[0][0] = -100.0;
	vertices[0][1] = 100.0;
	vertices[0][2] = 100.0;

	vertices[1][0] = 100.0;
	vertices[1][1] = 100.0;
	vertices[1][2] = 100.0;

	vertices[2][0] = 100.0;
	vertices[2][1] = -100.0;
	vertices[2][2] = 100.0;

	vertices[3][0] = -100.0;
	vertices[3][1] = -100.0;
	vertices[3][2] = 100.0;
	//----------------------

	vertices[4][0] = -100.0;
	vertices[4][1] = 100.0;
	vertices[4][2] = -100.0;

	vertices[5][0] = 100.0;
	vertices[5][1] = 100.0;
	vertices[5][2] = -100.0;

	vertices[6][0] = 100.0;
	vertices[6][1] = -100.0;
	vertices[6][2] = -100.0;

	vertices[7][0] = -100.0;
	vertices[7][1] = -100.0;
	vertices[7][2] = -100.0;
	//----------------------

	vertices[8][0] = -100.0;
	vertices[8][1] = 100.0;
	vertices[8][2] = -100.0;

	vertices[9][0] = -100.0;
	vertices[9][1] = 100.0;
	vertices[9][2] = 100.0;

	vertices[10][0] = -100.0;
	vertices[10][1] = -100.0;
	vertices[10][2] = 100.0;

	vertices[11][0] = -100.0;
	vertices[11][1] = -100.0;
	vertices[11][2] = -100.0;
	//----------------------

	vertices[12][0] = 100.0;
	vertices[12][1] = 100.0;
	vertices[12][2] = -100.0;

	vertices[13][0] = 100.0;
	vertices[13][1] = 100.0;
	vertices[13][2] = 100.0;

	vertices[14][0] = 100.0;
	vertices[14][1] = -100.0;
	vertices[14][2] = 100.0;

	vertices[15][0] = 100.0;
	vertices[15][1] = -100.0;
	vertices[15][2] = -100.0;
	//----------------------

	vertices[16][0] = -100.0;
	vertices[16][1] = 100.0;
	vertices[16][2] = -100.0;

	vertices[17][0] = 100.0;
	vertices[17][1] = 100.0;
	vertices[17][2] = -100.0;

	vertices[18][0] = 100.0;
	vertices[18][1] = 100.0;
	vertices[18][2] = 100.0;

	vertices[19][0] = -100.0;
	vertices[19][1] = 100.0;
	vertices[19][2] = 100.0;
	//----------------------

	vertices[20][0] = -100.0;
	vertices[20][1] = -100.0;
	vertices[20][2] = -100.0;

	vertices[21][0] = 100.0;
	vertices[21][1] = -100.0;
	vertices[21][2] = -100.0;

	vertices[22][0] = 100.0;
	vertices[22][1] = -100.0;
	vertices[22][2] = 100.0;

	vertices[23][0] = -100.0;
	vertices[23][1] = -100.0;
	vertices[23][2] = 100.0;

	return vertices;
}

void draw_3D_Object(vector<vector<double>> temp,int count) {
	vector<vector<double>> color(3, vector<double>(3, 0));
	
	//color for ORIGINAL object
	if (count == 0) {
		color[0][0] = 1.0f;
		
		color[1][1] = 1.0f;
		
		color[2][2] = 1.0;
	}
	//color for TRANSFORMED object
	if (count == 1) {
		color[0][0] = 179.0 / 255.0f;
		color[0][1] = 33.0 / 255.0f;
		color[0][2] = 33.0 / 255.0f;
	
		color[1][0] = 43.0 / 255.0f;
		color[1][1] = 179.0 / 255.0f;
		color[1][2] = 33.0 / 255.0f;
	
		color[2][0] = 33.0 / 255.0f;
		color[2][1] = 57.0 / 255.0f;
		color[2][2] = 179.0 / 255.0f;
	}

	glBegin(GL_QUADS);

	//Color for FRONT and BACK sides of the 3D object
	glColor4f(color[0][0], color[0][1], color[0][2],0.5);

	for (int i = 0; i < 24; i++) {
		//Color for LEFT and RIGHT sides of the 3D object
		if (i == 8 )
			glColor4f(color[1][0], color[1][1], color[1][2], 0.5);
		
		//Color for TOP and BOTTOM sides of the 3D object
		if (i == 16 )
			glColor4f(color[2][0], color[2][1], color[2][2], 0.5);
		
		glVertex3f(temp[i][0], temp[i][1], temp[i][2]);

		if ( (i+1) % 4 == 0) {
			glEnd();	//END if 4 end-points are plotted
			if(i!=23)	glBegin(GL_QUADS);	//BEGIN if not the end of ARRAY
		}
	}
}

//Transformations - Built-in functions- only for reference

void disp()
{
	glRotatef(45, 1, 0, 0);
	glRotatef(45, 0, 1, 0);
	glRotatef(0, 0, 0, 1);
}