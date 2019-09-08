#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct movie_t{
	char   title[88]; 	// 88  bytes
	int    year; 		// 4   bytes
	double box_office; 	// 8   bytes
};				// 100 bytes?
typedef struct movie_t movie;

struct friend_t{
	char name[1024];
	int n_movies;
	movie* movies;
};
typedef struct friend_t friend;

void printMovie(movie* m){ 
	printf("%15s(%d), lifetime gross %8.3lf million, address:%d \n", 
			m->title, m->year, m->box_office, m);
}

int main() {
	friend f;
	strcpy(f.name, "Jack");
	f.n_movies = 3;
	f.movies = malloc(sizeof(movie) * f.n_movies);

	strcpy(f.movies[0].title, "Titanic");
	f.movies[0].year = 1997;
	f.movies[0].box_office = 2187.463;
	printf("movies[0]:\n");
	printMovie(f.movies);
	//printMovie(&jack.movies[0]);

	movie bh;
	strcpy(bh.title, "Braveheart");
	bh.year = 1995;
	bh.box_office = 213.216;
	f.movies[1] = bh;
	printf("movies[1]:\n");
	printMovie(f.movies + 1);
	//printMovie(&f.movies[1]);

	movie* p_gf = &f.movies[2];
	strcpy(p_gf->title, "Godfather");
	p_gf->year  = 1972;
	p_gf->box_office = 245.066;
	printf("movies[2]:\n");
	printMovie(f.movies + 2);
	//printMovie(&f.movies[2]);

	printf("Our friend %s likes %d movies: \n", f.name, f.n_movies);
	for(int i = 0; i < f.n_movies; i ++) {
		printf("     %d", i+1);
		printMovie(f.movies + i);
		//printMovie(&jack.movies[i]); 
	}

	printf("\nSize of movie itself(struct movie_t): %4ld bytes\n", sizeof(bh));
	printf("Size of movie title(char[88]):        %4ld bytes\n", sizeof(bh.title));
	printf("Size of movie year(int):              %4ld bytes\n", sizeof(bh.year));
	printf("Size of movie box_office(double):     %4ld bytes\n", sizeof(bh.box_office));

	return 0;	

}
