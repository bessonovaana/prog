#include<iostream>
#include<cmath>
#include<vector>

using namespace std;
class point{
    public:
    double x;
    double y;
};
class quadrilateral{
    protected:
       std::vector<point>points;
    public:
    quadrilateral(const std::vector<point>& points):points(points){}
        
    bool check(){
        return !((points[0].x == points[1].x && points[1].x == points[2].x && points[2].x == points[3].x)
                 || (points[0].y == points[1].y && points[1].y == points[2].y && points[2].y == points[3].y));
    }
    
    double sides(int i, int j){
        return sqrt(pow(points[j].x - points[i].x, 2) + pow(points[j].y - points[i].y, 2));
    }
    double perimetr(){
       double perimeter = 0;
        for (int i = 0; i < 3; ++i) {
            perimeter += sides(i, i + 1);
        }
        perimeter += sides(3, 0); // Добавляем последнюю сторону
        return perimeter;
    }
    
    void outputTo(){
        std::cout<<"Координаты точек: A("<<points[0].x<<","<<points[0].y<<"), B("<<points[1].x<<","<<points[1].y<<"), C("<<points[2].x<<","<<points[2].y<<"), D("<<points[3].x<<","<<points[3].y<<")"<<endl;
        std::cout<<"Периметр чеиырехугольника: "<<perimetr()<<endl;
    }
};

class parallelogram: public quadrilateral{
public:
    parallelogram(const std::vector<point>& points):quadrilateral(points){}
    bool checkP(){
      return  (sides(0,1)==sides(2,3) && sides(1,2)==sides(3,0));
    }
    double square(){
        double x1 = points[1].x - points[0].x;
        double y1 = points[1].y - points[0].y;
        double x2 = points[2].x - points[0].x;
        double y2 = points[2].y - points[0].y;
        return std::abs(x1 * y2 - x2 * y1);
    }
    void outp(){
        std::cout<<"Координаты точек: A("<<points[0].x<<","<<points[0].y<<"), B("<<points[1].x<<","<<points[1].y<<"), C("<<points[2].x<<","<<points[2].y<<"), D("<<points[3].x<<","<<points[3].y<<")"<<endl;
        std::cout<<"Периметр параллелограмма: "<<perimetr()<<endl;
        std::cout<<"Площадь параллелограмма: "<<square()<<endl;
    }

};
int main(){
    int n, k=0;
    double s=0, sr=0, max=0, min=10000;
    std::cout<<"введите количество четырехугольников: "<<endl;
    cin>>n;
    std::vector<quadrilateral>quadrilaterals;
    std::vector<double>perimetrs;
    std::vector<parallelogram>parallelograms;
    std::vector<double>squares;
    for (int i=0; i<n; ++i){
        std::vector<point>points;
        std::cout << "Введите координаты вершин параллелограмма " << i + 1 << " (в формате x y):" <<endl;
        for (int j=0;j<4;++j){
            point pt;
            cin>>pt.x>>pt.y;
            points.push_back(pt);
        }
        parallelogram p(points);
        if (p.check()){
            quadrilaterals.push_back(p);
            perimetrs.push_back(p.perimetr());
            if (p.checkP()){
                parallelograms.push_back(p);
                squares.push_back(p.square());
                if (p.square()>max){
                    max=p.square();
                }
                if (p.square()<min){
                    min=p.square();
                }
                s+=p.square();
                k+=1;
                p.outp();
            }
            else{
                p.outputTo();
                std::cout<<"это не параллелограмм"<<endl;
            }
        }
        else{
            std::cout<<"что-то странное"<<endl;
        }

    }
    
    if (k>0){
        sr=s/k;
        std::cout<<"средняя площадь "<<k<<" параллелограммов равна "<<sr<<endl;
        std::cout<<"большая площадь параллеграмма "<<max<<endl;
        std::cout<<"меньшая площадь параллеграмма "<<min<<endl;
    }
    }