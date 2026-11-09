# Replace with your unique project name

Cones4Color

## Description

version 1.0

allows the comparison between two rgb colors wheather they are considered dangerously close, iffily close, or well enough apart to be considerd good. program is repeated until user opts out

version 2.0 Updates

allows the comparison between two or more Hex colors 
if only comparing two colors the program provides their difference in luminosity
if comparing more than two colors the program will provide the user the two colors in their palette who based on luminosity are the closest in value
--> this allows the user to tweak their closest colors in hopes of having wide enough differences between all the colors in their palette

## Developer

Fiona Wiersch

## Example

To run the program, give the following commands:

```
g++ --std=c++11 *.cpp -o cvp
./cvp
```

input hex #RRGGBB (type 'done' once all colors are inputed): #123456
input hex #RRGGBB (type 'done' once all colors are inputed): #F1017A
input hex #RRGGBB (type 'done' once all colors are inputed): #098765
input hex #RRGGBB (type 'done' once all colors are inputed): #ABCDEF
input hex #RRGGBB (type 'done' once all colors are inputed): done
comparing...
#123456
#F1017A
#098765
#ABCDEF
The Hex values of #F1017A and #098765 have the closest luminosity with a difference of 6.896
differences lower than 2-3% are generally considered undetectable.