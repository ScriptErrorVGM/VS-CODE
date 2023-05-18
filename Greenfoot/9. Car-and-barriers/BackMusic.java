import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

/**
 * Write a description of class BackMusic here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class BackMusic extends Actor
{
    GreenfootSound ambient = new GreenfootSound("ambient.mp3");
    GreenfootSound gameover = new GreenfootSound("game-over.mp3");
    /**
     * Act - do whatever the BackMusic wants to do. This method is called whenever
     * the 'Act' or 'Run' button gets pressed in the environment.
     */
    public void BackMusic(){
        MyWorld world = (MyWorld) getWorld();
            if(world.getObjects(Car.class).size() == 1){
                ambient.setVolume(50);
                ambient.playLoop(); 
            }else if (world.getObjects(Car.class).size() < 1){
                ambient.stop();
                gameover.setVolume(50);
                gameover.playLoop();
            }
    
    }
    
    public void act()
    {
        BackMusic();
    }
}
