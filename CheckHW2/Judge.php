<?php
	session_start();
	$ID=$_SESSION['user'];
	$code=$_POST['cppfile'];
	$header=$_POST['hfile'];
	/*save code*/
	$fileh = fopen("./tmpCode/".$ID."/Sudoku.h","w");
	fwrite($fileh,$header); fclose($fileh);
	$filecpp = fopen("./tmpCode/".$ID."/Sudoku.cpp","w");
	fwrite($filecpp,$code); fclose($filecpp);
	/*compile*/
	exec('g++ -c ./tmpCode/'.$ID.'/Sudoku.cpp -o ./tmpCode/'.$ID.'/Sudoku.o 2>&1',$ce);
	if(!empty($ce)){
		echo '<img src="StatusImg/ce.png" /><br/>';
		echo '<hr style="border-top:dashed 1px;"/>';
		echo '<p>';
		foreach($ce as $item) echo $item.'<br/>';
		echo '</p>';
		shell_exec("rm ./tmpCode/".$ID."/question*");
		exit(); 
	}
	/*********/
	/*make execution file*/
	shell_exec('cp ./Code/* ./tmpCode/'.$ID.'/ ');
	shell_exec('g++ -o ./tmpCode/'.$ID.'/hw2_check ./tmpCode/'.$ID.'/hw2_check.cpp ./tmpCode/'.$ID.'/Sudoku.o');
	shell_exec('g++ ./tmpCode/'.$ID.'/hw2_solve.cpp ./tmpCode/'.$ID.'/Sudoku.o ./tmpCode/'.$ID.'/Clock.o -o ./tmpCode/'.$ID.'/hw2_solve');
	shell_exec('g++ -o ./tmpCode/'.$ID.'/hw2_give_question ./tmpCode/'.$ID.'/Sudoku.o ./tmpCode/'.$ID.'/hw2_give_question.cpp');
	shell_exec('g++ -o ./tmpCode/'.$ID.'/hw2_check_give ./tmpCode/'.$ID.'/hw2_check_give.cpp ./tmpCode/'.$ID.'/CheckSudoku.o');
	/*********************/
?>