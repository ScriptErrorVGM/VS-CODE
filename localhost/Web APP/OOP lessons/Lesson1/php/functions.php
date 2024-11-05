<?php
    require "includes/config.php";

    function dbConnect(){

        $mysqli = new mysqli(SERVER, USERNAME, PASSWORD, DATABASE);

        if($mysqli->connect_errno != 0){

            return FALSE;

        }else{

            return $mysqli;
        }
    }

    function getCategories(){

        $mysqli = dbConnect();

        $result = $mysqli->query("SELECT DISTINCT category FROM products");

        while($row = $result ->fetch_assoc()){

            $categories[] = $row;
        }
        return $categories;
    }