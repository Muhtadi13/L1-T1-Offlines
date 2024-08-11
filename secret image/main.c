#include <stdio.h>
#include <stdlib.h>
typedef struct Color
{
    int R;
    int G;
    int B;
} Color;


typedef struct Image
{
    Color **image;
    int rows;
    int cols;
} Image;


Image *read_PPM(char *filename)
{
    FILE *fp;
    int max_pixel,i,j,dim;
    char name[100];
    Image *im=(Image *)malloc(sizeof(Image));

    if((fp=fopen(filename,"r"))==NULL)
    {
        printf("ERROR");
        exit(1);
    }
    fscanf(fp,"%s",name);
    fscanf(fp," %d",&im->cols);
    fscanf(fp," %d",&im->rows);
    fscanf(fp," %d",&max_pixel);

    dim=im->cols*im->rows;

    im->image=(Color **)malloc(sizeof(Color*)*im->rows);

    for(i=0; i<im->rows; i++)
    {
        im->image[i]=(Color *)malloc(im->cols*sizeof(Color));
        if(im->image[i]==NULL)
            printf("Unsuccessful memory allocation ");

    }
    for(i=0; i<im->rows; i++)
    {
        for(j=0; j<im->cols; j++)
        {
            fscanf(fp," %d",&im->image[i][j].R);
            fscanf(fp," %d",&im->image[i][j].G);
            fscanf(fp," %d",&im->image[i][j].B);
        }
    }
    return im;




}

void write_PPM(Image *im,char *filename)
{
    FILE *fptr;
    int max_pixel=255,i,j;

    if((fptr=fopen(filename,"w"))==NULL)
    {
        printf("ERROR");
        exit(1);
    }
    fprintf(fptr,"P3\n");
    fprintf(fptr,"%d  ",im->cols);
    fprintf(fptr,"%d\n",im->rows);
    fprintf(fptr,"%d\n  ",max_pixel);
    for(i=0; i<im->rows; i++)
    {
        for(j=0; j<im->cols; j++)
        {
            fprintf(fptr,"%d   ",im->image[i][j].R);
            fprintf(fptr,"%d   ",im->image[i][j].G);
            fprintf(fptr,"%d     ",im->image[i][j].B);
        }
        fprintf(fptr,"\n");
    }

}

void free_image(Image *im)
{
    int i;

    for(i=0; i<im->rows; i++)
    {
        free(im->image[i]);

    }
    free(im->image);


}

Color *evaluate_one_pixel(Image *im,int row,int col)
{
    Color *clr=(Color *)malloc(sizeof(Color));

    if((im->image[row][col].B)%2==0)
    {
        clr->R=0;
        clr->G=0;
        clr->B=0;

    }

    else
    {
        clr->R=255;
        clr->G=255;
        clr->B=255;
    }
    return clr;
}

Image *get_secret_image(Image *im)
{
    Color *cr;
    int i,j;
    for(i=0; i<im->rows; i++)
    {
        for(j=0; j<im->cols; j++)
        {
            cr=evaluate_one_pixel(im,i,j);

            im->image[i][j].R=cr->R;
            im->image[i][j].G=cr->G;
            im->image[i][j].B=cr->B;

            free(cr);


        }
    }
    return im;
}




int main()
{
    char name1[]="DennisRitchie.ppm";
    char name2[]="secret_message.ppm";

    Image *im1=read_PPM(name1);
    Image *im2=get_secret_image(im1);


    write_PPM(im2,name2);

    free_image(im1);



    return 0;
}
