#include <iostream>
#include <random>
#include <cstdlib>

using namespace std;


struct Point2D{
    double x;
    double y;
};

struct Polygon2D{
    int vertices_count;
    Point2D* vertices;
};

struct CountryPopulation{
    double populationInMillions;
    double countryAreaInKm2;
};


void print_point(Point2D point){
    printf("(%.2f,%.2f)",point.x,point.y);
}

void print_polygon(Polygon2D polygon){
    printf("Polygon2D: [\n    ");
    for (int i=0; i<polygon.vertices_count; i++){
        print_point(polygon.vertices[i]);
        if ((i+1)%5==0){
            printf("\n");
        } else {
            printf(", ");
        }
    }
    printf("\n]\n");
}

void delete_polygon(Polygon2D polygon){
    delete(polygon.vertices);
    delete(&polygon);
}

void task10_6_k(){
    size_t polygon_size;

    printf("Polygon Size >0 :");
    scanf("%d",&polygon_size);

    if (polygon_size<=0) return;

    Point2D* vertices = (Point2D*)calloc(polygon_size,sizeof(Point2D));

    for (int i=0; i<polygon_size; i++){
        Point2D vertex_i;

        double x;
        double y;

        printf("Input X coordinate of vertex %d of polygon: ",i+1);
        scanf("%lf",&x);

        printf("Input Y coordinate of vertex %d of polygon: ",i+1);
        scanf("%lf",&y);

        cout<<endl;

        vertex_i.x=x;
        vertex_i.y=y;

        vertices[i]=vertex_i;
    }

    Polygon2D polygon;

    polygon.vertices_count=polygon_size;
    polygon.vertices=vertices;

    print_polygon(polygon);
    delete_polygon(polygon);
}

void task10_10(){
    CountryPopulation populations[5] = {
        {10,50000},
        {253,105930},
        {530,350203},
        {15.5,127000},
        {1000,400000}
    };

    CountryPopulation minimumDensity = populations[0];

    for (int i=1; i<5; i++){
        CountryPopulation population = populations[i];

        if (population.populationInMillions/population.countryAreaInKm2 < 
            minimumDensity.populationInMillions/minimumDensity.countryAreaInKm2){
            minimumDensity = population;
        }
    }

    printf("Population with minimum density:\n");
    printf("Population:\n  %.3fm people\n  Country area size: %.3f\n",
        minimumDensity.populationInMillions,
        minimumDensity.countryAreaInKm2);
    
}

int main(){
    //11 Красовський Олександр 10.06к, 10.10
    task10_6_k();
    task10_10();
    return 0;
}