<h1 align="center">
  Common Core 42 - FdF
</h1>

<p align="center">
<img src="https://github.com/tmatheusdiniz/42-FdF/releases/download/img/42_map.png" width="900" hidth="150">
</P>
<p align="center">
    <b><i>This project is part of second milestone of the 42 cursus</i></b>
</p>
<h3 align="center">
    <a href="#--fdf">Score/Demos</a>
    <span> · </span>
    <a href="#-about">About</a>
    <span> · </span>
    <a href="#%EF%B8%8F-usage">Usage</a>
    <span> · </span>
    <a href="#-references">References</a
</h3>

## 🎢  fdf
<br>
<div align="center">
    <p><i>This project has already been graded</i></p>
    <img src="https://github.com/tmatheusdiniz/42-libft/releases/download/Note/score.png")>
</div>
<br>
<div align="center">
<b>Below you can see some demos of the maps running on my computer</b>
</div>
<p align="center">
<img src="https://github.com/tmatheusdiniz/42-FdF/releases/download/img/julia_map.png" width="900" hidth="150">
</P>
<p align="center">
<img src="https://github.com/tmatheusdiniz/42-FdF/releases/download/img/cord_map.png" width="900" hidth="150">
</P>

## 📖 About
> The aim of this project is to create a program that transforms a 2d map input into a 3d landscape. 
> 
> I decided to make the project complete (with the bonus part).
### 🧐 How can you use fdf program
> For run the program you will need have Linux or Mac how operations system.
>
To pull files ↙️
```bash
git clone https://github.com/tmatheusdiniz/42-FdF.git
```
To compile the program ↙️
```bash
$ make
```
>After the “make” command, the dependencies will automatically be downloaded to your computer.
>So all you have to do afterwards is run the program.
>
To load you have to launch the program with a valid map as parameter 🗺️
```bash
$ ./bin/fdf maps/valid_map.fdf
```

## 🛠️ Usage
<div align="center">
<b>The program has some controls</b>
  
|TECLA|ACCION|
|---|---|
|`Keys w, s, a and d`| For translational movements in X/Y|
|`Mouse (Left Clicked)`| Traslation also in any direction that you chosse|
|`Mouse Scroll`| Zomm In/Out|
|`Arrows`| Rotation the map|
|`Q / E`| Rotation the map in z axis|
|`MOuse (right clicked)`| Allow run the animation|
|`X/Y/Z`| After allowing the animation to run, click on x, y or z to run the animation|
|`MOuse (right cliked)`| Right clicked again to stop the animation|
|`ESC ❌`| Exit of the program|

</div>

## 📚 References

Rotations matrix : https://www.mathforengineers.com/math-calculators/3D-point-rotation-calculator.html#google_vignette\

Orthographic Projections : https://learnwebgl.brown37.net/08_projections/projections_ortho.html

Minilibx : https://gontjarow.github.io/MiniLibX/mlx-tutorial-create-image.html
