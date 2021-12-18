all:
	g++ -w src/main.cpp -w src/game.cpp -w src/deathBall.cpp -w src/goodBall.cpp -o main -Wall -lSDL2 -lSDL2_ttf -lSDL2_image -I include
clean:
	rm ./main