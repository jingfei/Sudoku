## Environment setting

- Laravel PHP Framework ([Official Documentation](http://laravel.com/docs))
- `app/controllers/BaseController.php`  has a protected static variable `$CodePath` , it is Sudoku code’s base path (absolute path, ex. `/home/xxx/Sudoku` ). The checking code and everyone’s code is saved in the directory.
- In `$CodePath` , there are at least three directory.
  -  `$CodePath/Code` : Save main code to execute user’s uploaded code. 
  -  `$CodePath/tmpCode` : In the directory, there are directories with student’s ID number, and their code are in their own directory. Remember to set all the file owner `www-data:TAs` .
  -  `$CodePath/outputs` : Testcases input and output files are in `$CodePath/outputs/Q`  and `$CodePath/outputs/A` separately.

## Main idea

- Provide students to check correctness of their sudoku code. It is required to separate the code into one header and one cpp files.
- Let students challenge each other by solving time and win the contest.

## Controllers

- `BaseController` : All common functions.
- `HomeController` : Calculate the rank of each student and make rank (home) page.
- `CompilerController` : Compile the uploaded code, and check them. Including solve and give_question code.
- `AttackController` :  Attack controller, execute two competitors code, calculate time and judge it.

## Laravel PHP Framework

[![Build Status](https://travis-ci.org/laravel/framework.svg)](https://travis-ci.org/laravel/framework)
[![Total Downloads](https://poser.pugx.org/laravel/framework/downloads.svg)](https://packagist.org/packages/laravel/framework)
[![Latest Stable Version](https://poser.pugx.org/laravel/framework/v/stable.svg)](https://packagist.org/packages/laravel/framework)
[![Latest Unstable Version](https://poser.pugx.org/laravel/framework/v/unstable.svg)](https://packagist.org/packages/laravel/framework)
[![License](https://poser.pugx.org/laravel/framework/license.svg)](https://packagist.org/packages/laravel/framework)

Laravel is a web application framework with expressive, elegant syntax. We believe development must be an enjoyable, creative experience to be truly fulfilling. Laravel attempts to take the pain out of development by easing common tasks used in the majority of web projects, such as authentication, routing, sessions, and caching.

Laravel aims to make the development process a pleasing one for the developer without sacrificing application functionality. Happy developers make the best code. To this end, we've attempted to combine the very best of what we have seen in other web frameworks, including frameworks implemented in other languages, such as Ruby on Rails, ASP.NET MVC, and Sinatra.

Laravel is accessible, yet powerful, providing powerful tools needed for large, robust applications. A superb inversion of control container, expressive migration system, and tightly integrated unit testing support give you the tools you need to build any application with which you are tasked.

### License

The Laravel framework is open-sourced software licensed under the [MIT license](http://opensource.org/licenses/MIT)
