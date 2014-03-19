<?php
	require_once("db_const.php");
	include 'Func.php';
	$ID=$_SESSION['id'];
	$op=$_POST['op'];
	/*update code*/
	UpdateCode($_POST['cppfile'],$_POST['hfile']);
	/***********/
	/*compile*/
	exec('g++ -c ./tmpCode/'.$ID.'/Sudoku.cpp -o ./tmpCode/'.$ID.'/Sudoku.o 2>&1',$ce);
	if(!empty($ce)){
		compile_error($ce,$score); 
	//	shell_exec("find ./tmpCode/".$ID." -type f -not -name 'Sudoku.*' | xargs rm");
		shell_exec("rm ./tmpCode/".$ID."/question*");
		Record($op,1,-2,'-1','0');
		exit(); 
	}
	/*********/
	/*make execution file*/
	shell_exec('cp ./Code/* ./tmpCode/'.$ID.'/ ');
	shell_exec('g++ -o ./tmpCode/'.$ID.'/hw2_check ./tmpCode/'.$ID.'/hw2_check.cpp ./tmpCode/'.$ID.'/Sudoku.o');
	shell_exec('g++ ./tmpCode/'.$ID.'/hw2_solve.cpp ./tmpCode/'.$ID.'/Sudoku.o ./tmpCode/'.$ID.'/Clock.o -o ./tmpCode/'.$ID.'/hw2_solve');
	shell_exec('g++ -o ./tmpCode/'.$ID.'/hw2_give_question ./tmpCode/'.$ID.'/Sudoku.o ./tmpCode/'.$ID.'/hw2_give_question.cpp');
	shell_exec('g++ -o ./tmpCode/'.$ID.'/hw2_check_give ./tmpCode/'.$ID.'/hw2_check_give.cpp');
	/*********************/
?>
