import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

/**
 * Write a description of class MyWorld here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class MyWorld extends World
{

    /**
     * Constructor for objects of class MyWorld.
     * 
     */
    public MyWorld()
    {    
        // Create a new world with 600x400 cells with a cell size of 1x1 pixels.
        super(600, 400, 1); 
        setBackground("Wall.jpg");
        populate();
    }
    
    public void populate() {
        int[][] array = new int[8][2];
        for (int i = 0; i < array.length; i++) {
                    int x = Greenfoot.getRandomNumber(getWidth());
                    int y = Greenfoot.getRandomNumber(getHeight());
                    array[i][0] = x;
                    array[i][1] = y;
		}
	for (int i = 0; i < array.length; i++) {
            if (i%4 == 0){
                addObject(new predator(),array[i][0],array[i][1]);
            } else {
                addObject(new prey(),array[i][0],array[i][1]);
            }
        }
			
    }
}
