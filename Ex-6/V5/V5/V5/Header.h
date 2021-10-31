#pragma once

void draw_X_Y_plane() {

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2d(-700, 0);
	glVertex2d(700, 0);
	glVertex2d(0, -700);
	glVertex2d(0, 700);
	glEnd();
}
void drawPolygon()
{
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0/255.0f, 0.0 / 255.0f, 102.0 / 255.0f);
	for (int i = 0; i < n; i++)
	{
		glVertex2d(coords[i].first, coords[i].second);
	}
	glEnd();
}
vector<vector<double>> translate()
{
	vector<vector<double>> temp(3, vector<double>(3, 0));

	temp[0][0] = 1;
	temp[1][1] = 1;
	temp[2][2] = 1;
	temp[0][2] = tx;
	temp[1][2] = ty;
		
	return temp;
}
vector<vector<double>> rotate_fixed() {
	vector<vector<double>> temp(3, vector<double>(3, 0));

	temp[0][0] = cos(angRad);
	temp[1][1] = cos(angRad);
	temp[2][2] = 1;
	temp[1][0] = sin(angRad);
	temp[0][1] = -1 * sin(angRad);
	temp[0][2] = xr * (1 - cos(angRad)) + yr * sin(angRad);
	temp[1][2] = yr * (1 - cos(angRad)) - xr * sin(angRad);
	
	return temp;
}
vector<vector<double>>  scale_fixed() {
	vector<vector<double>> temp(3, vector<double>(3, 0));

	temp[0][0] = sx;
	temp[1][1] = sy;
	temp[2][2] = 1;
	temp[0][2] = xf * (1 - sx);
	temp[1][2] = yf * (1 - sy);
	
	return temp;
}
vector<vector<double>> reflect_X() {
	vector<vector<double>> temp(3, vector<double>(3, 0));

	temp[0][0] = 1;
	temp[1][1] = -1;
	temp[2][2] = 1;
	
	return temp;
}
vector<vector<double>> reflect_Y() {
	vector<vector<double>> temp(3, vector<double>(3, 0));

	temp[0][0] = -1;
	temp[1][1] = 1;
	temp[2][2] = 1;
	
	return temp;
}
vector<vector<double>> reflect_Origin() {
	vector<vector<double>> temp(3, vector<double>(3, 0));

	temp[0][0] = -1;
	temp[1][1] = -1;
	temp[2][2] = 1;
	
	return temp;
}
vector<vector<double>> reflect_X_Y() {
	vector<vector<double>> temp(3, vector<double>(3, 0));

	temp[0][1] = 1;
	temp[1][0] = 1;
	temp[2][2] = 1;
	
	return temp;
}
vector<vector<double>> shear_X() {
	vector<vector<double>> temp(3, vector<double>(3, 0));

	temp[0][0] = 1;
	temp[1][1] = 1;
	temp[2][2] = 1;
	temp[0][1] = sh;
		
	return temp;
}
vector<vector<double>> shear_Y() {
	vector<vector<double>> temp(3, vector<double>(3, 0));

	temp[0][0] = 1;
	temp[1][1] = 1;
	temp[2][2] = 1;
	temp[1][0] = sh;
		
	return temp;
}
vector<vector<double>> executeTransformMatrix(int opt) {
	vector<vector<double>> trans_mat(3, vector<double>(3, 0));

	if (opt == 1)			 trans_mat = translate();
	else if (opt == 2)		 trans_mat = rotate_fixed();
	else if (opt == 3)		 trans_mat = scale_fixed();
	else if (opt == 4) {
		if (rfl == 'a')		 trans_mat = reflect_X();
		else if (rfl == 'b') trans_mat = reflect_Y();
		else if (rfl == 'c') trans_mat = reflect_Origin();
		else if (rfl == 'd') trans_mat = reflect_X_Y();
	}
	else {
		if (shd == 'a')		 trans_mat = shear_X();
		else				 trans_mat = shear_Y();
	}
	
	return trans_mat;
}
void draw_Transformed_Polygon(vector<vector<double>> trans_1, vector<vector<double>> trans_2) {

	/*Multiply the two transformation matrices to find the
	final TRANSFORMATION matrix*/
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				Transformation[i][j] += trans_1[i][k] * trans_2[k][j];
			}
		}
	}

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 0.0, 0.0);
	vector<pair<int, int>> newVertices;
	vector<double> curpoint(3, 0), matProduct(3, 0);
	for (int i = 0; i < n; i++) {
		curpoint[0] = coords[i].first;
		curpoint[1] = coords[i].second;
		curpoint[2] = 1;
		matProduct[0] = 0;
		matProduct[1] = 0;
		matProduct[2] = 0;
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				//Apply the TRANSFORMATION matrix to all the vertices
				matProduct[j] += Transformation[j][k] * curpoint[k];
			}
		}
		newVertices.push_back(make_pair(round(matProduct[0]), round(matProduct[1])));

	}
	for (int i = 0; i < n; i++)
	{
		glVertex2d(newVertices[i].first, newVertices[i].second);
	}
	glEnd();
}