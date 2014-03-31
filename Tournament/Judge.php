<?php
	require_once("db_const.php");
	include 'Func.php';
	$ID=$_SESSION['id'];
	$op=$_POST['op'];
	/*update code*/
	UpdateCode($_POST['cppfile'],$_POST['hfile']);
	/***********/
	/*save code*/
//	$fileh = fopen("./tmpCode/".$ID."/Sudoku.h","w");
//	fwrite($fileh,$header); fclose($fileh);
//	$filecpp = fopen("./tmpCode/".$ID."/Sudoku.cpp","w");
//	fwrite($filecpp,$code); fclose($filecpp);
	/**********/
	/*compile*/
	exec('g++ -c ./tmpCode/'.$ID.'/Sudoku.cpp -o ./tmpCode/'.$ID.'/Sudoku.o 2>&1',$ce);
	if(!empty($ce)) CompileError($ce,$ID,$score,$op);
	/*********/
	/*make execution file*/
	shell_exec('cp ./Code/* ./tmpCode/'.$ID.'/ ');
	exec('g++ -o ./tmpCode/'.$ID.'/hw2_check ./tmpCode/'.$ID.'/hw2_check.cpp ./tmpCode/'.$ID.'/Sudoku.o 2>&1',$ce);
	if(!empty($ce)) CompileError($ce,$ID,$score,$op);
	exec('g++ ./tmpCode/'.$ID.'/hw2_solve.cpp ./tmpCode/'.$ID.'/Sudoku.o ./tmpCode/'.$ID.'/Clock.o -o ./tmpCode/'.$ID.'/hw2_solve 2>&1',$ce);
	if(!empty($ce)) CompileError($ce,$ID,$score,$op);
	exec('g++ -o ./tmpCode/'.$ID.'/hw2_give_question ./tmpCode/'.$ID.'/Sudoku.o ./tmpCode/'.$ID.'/hw2_give_question.cpp 2>&1',$ce);
	if(!empty($ce)) CompileError($ce,$ID,$score,$op);
	exec('g++ -o ./tmpCode/'.$ID.'/hw2_check_give ./tmpCode/'.$ID.'/hw2_check_give.cpp 2>&1',$ce);
	if(!empty($ce)) CompileError($ce,$ID,$score,$op);
	/*********************/
	function CompileError($ce,$ID,$score,$op){
		compile_error($ce,$score); 
		shell_exec("rm ./tmpCode/".$ID."/question*");
		Record($op,1,-2,'-1','0');
		exit(); 
	}
?>
