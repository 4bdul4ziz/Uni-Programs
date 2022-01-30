//take vector input into class variable
//return class variable
class Vector
{
public:
    Vector(double x, double y, double z);
    Vector();
    double getX();
    double getY();
    double getZ();
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    Vector operator+(Vector v);
    Vector operator-(Vector v);
    Vector operator*(double d);
    Vector operator/(double d);
    double dot(Vector v);
    Vector cross(Vector v);
    double magnitude();
    Vector normalize();
    double getAngle(Vector v);
    double getAngle(Vector v, Vector u);
    double getAngle(Vector v, Vector u, Vector w);
    double getAngle(Vector v, Vector u, Vector w, Vector x);
    double getAngle(Vector v, Vector u, Vector w, Vector x, Vector y);
    double getAngle(Vector v, Vector u, Vector w, Vector x, Vector y, Vector z);
    double getAngle(Vector v, Vector u, Vector w, Vector x, Vector y, Vector z, Vector a);
    double getAngle(Vector v, Vector u, Vector w, Vector x, Vector y, Vector z, Vector a, Vector b);
    double getAngle(Vector v, Vector u, Vector w, Vector x, Vector y, Vector z, Vector a, Vector b, Vector c);
    double getAngle(Vector v, Vector u, Vector w, Vector x, Vector y, Vector z, Vector a, Vector b, Vector c, Vector d);
    double getAngle(Vector v, Vector u, Vector w, Vector x, Vector y, Vector z, Vector a, Vector b, Vector c, Vector d, Vector e);
    double getAngle(Vector v, Vector u, Vector w, Vector x, Vector y, Vector z, Vector a, Vector b, Vector c, Vector d, Vector e, Vector f);
    double getAngle(Vector v, Vector u, Vector w, Vector x, Vector y, Vector z, Vector a, Vector b, Vector c, Vector d, Vector e, Vector f, Vector g);
    double getAngle(Vector v, Vector u, Vector w, Vector x, Vector y, Vector z, Vector a, Vector b, Vector c, Vector d, Vector e, Vector f, Vector g, Vector h);
} vector<Vector> getVector(int n);
Vector::Vector(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

vector<Vector> getVector(int n)
{
    vector<Vector> v;
    for (int i = 0; i < n; i++)
    {
        double x, y, z;
        cin >> x >> y >> z;
        v.push_back(Vector(x, y, z));
    }
    return v;
}