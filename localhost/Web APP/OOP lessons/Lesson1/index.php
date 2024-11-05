<?php require "php/functions.php" ?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0" >
    <meta name="description" content="Our shop can provide you with various collections of digital products">
    <meta name="keywords" content="books, games, art">
    <link rel="stylesheet" href="css/styles.css">
    <title>Our Shop</title>
</head>

<body>


    <?php include "includes/nav.php" ?>

    <?php include "includes/header.php" ?>


    <main>

        <div class="left">

               <div class="section-title">Product Cotegories</div> 
                <?php $category = getCategories() ?>
                <?php
                    foreach ($category as $category) {
                        ?>
                        <a href="category.php?category=<?php echo urlencode($category['category'])?>">

                            <?php echo ucfirst($category['category']) ?>

                        </a>
                        <?php
                    }
                ?>
        </div>
        
        <div class="right">

            <div class="section-title">Home page</div>

            <div class="product">

                <div class="product-left">
                    <img src="products/coding.jpg" alt="">
                </div>
                        
                <div class="product-right">

                        <p class="title">
                            <a href="">Coding is fun</a>
                        </p>
                        <p class="desscription">

                            Lorem ipsum odor amet, consectetuer adipiscing elit. Lorem ipsum odor amet, consectetuer adipiscing elit.

                        </p>
                        <p class="price">
                            39.99 &dollar;
                        </p>   
                </div> 
                        
            </div>
        </div>
    </main>

    <?php include "includes/footer.php" ?>

    

    <script src="javascrpit/script.js"></script>
</body>
</html>