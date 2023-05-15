import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

/**
 * Write a description of class Car here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Car extends Actor
{
    private GreenfootImage image1;
    int speed = 0;
    int dr = 0;
    final int MAX_SPEED = 4;
    final int MIN_SPEED = -4;
    final int DELAY = 20;
    
    /**
     * Act - do whatever the Car wants to do. This method is called whenever
     * the 'Act' or 'Run' button gets pressed in the environment.
     */
    public Car(){
        
        image1 = new GreenfootImage("car02.png");
        
        //GreenfootImage image = getImage();
        
        //int myH = (int)image.getHeight();
        //int myW = (int)image.getWidth();
        //image.scale(myW,myH);
        setImage("car02.png");
        Greenfoot.playSound("door.mp3");
    }
    
    public void act()
    {
        checkKeypress();
        move(speed);
        checkBarrier();
    }
    
    public void checkEngine(){
        if(speed == 0){
            Greenfoot.playSound("engine_rev.mp3");
            Greenfoot.delay(100);
        } 
    }
    
    public void checkBarrier(){
        //if(!getIntersectingObjects(Barrier.class).isEmpty()){
        MyWorld world = (MyWorld) getWorld();  
        if (isTouching(Barrier.class) ) {
            world.addObject(new crash(), getX(), getY());
            world.removeObject(this);
            //speed = 0;
            //move(speed);
            Greenfoot.playSound("car_crash_sound.mp3");   
            world.gameOver();
            
            //Greenfoot.stop();
        }
    }
    GreenfootSound turn = new GreenfootSound("turn_2 .wav");
    
    public void checkKeypress()
    {   
        
        if (Greenfoot.isKeyDown("space")) 
        {
            speed = 0;
        }
        if (Greenfoot.isKeyDown("up") && speed < MAX_SPEED )
        {
            checkEngine();
            move(speed++);
        }
        if (Greenfoot.isKeyDown("down") && speed > MIN_SPEED )
        {
            move(speed--);
        }
        if (Greenfoot.isKeyDown("left") && speed != 0) 
        {
            turn(-1-speed);
            if(!turn.isPlaying()){
                turn.setVolume(80);
                turn.play();
            }
            
            //Greenfoot.playSound("turn_2 .wav");
        }
        if (Greenfoot.isKeyDown("right") && speed != 0) 
        {
            turn(1+speed);
            if(!turn.isPlaying()){
                turn.setVolume(80);
                turn.play();
            }
            
            //Greenfoot.playSound("turn_2 .wav");
        }
    }
    
}
