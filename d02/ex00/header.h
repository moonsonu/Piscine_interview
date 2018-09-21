#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/
	struct s_stone {
		int size;
		struct s_stone *next;
	};

	struct s_group {
		int size;
		struct s_stone *first;
		struct s_stone *last;
		struct s_group *next;
	};


/*--------------------------------
  :) function you must implement
  --------------------------------*/
//stone is a pointer to the first
void sortStones(struct s_stone **stone);


/*--------------------------------
  ?? test function used in main
  --------------------------------*/
struct s_stone *genRandomStoneList(int n);
void printStone(struct s_stone *stone);
struct s_stone *createStone(int size);
void exitWithMsg(char *msg);


/*--------------------------------
  &  your own other function
  --------------------------------*/
void	swap(struct s_group *p1, struct s_group *p2);
struct s_group		*newgroup(struct s_stone *stone);
void	makegroup(struct s_group **g, struct s_stone *s);
struct s_stone	*merge(struct s_group *g);
struct s_group	*getgroup(struct s_stone *stone);
#endif
