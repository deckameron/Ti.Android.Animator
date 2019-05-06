# Ti.Android.Animator
A newer version of [@Animecyc](https://github.com/animecyc) Android [TitaniumAnimator](https://github.com/animecyc/TitaniumAnimator)

A drop-in animation replacement for Titanium. This module's aim is to mimick as much of the Titanium animation module as possible with the addition of new timing functions and better performance. As of right now the only properties that can be animated are: `rotate`, `transform`, `top`, `bottom`, `left`, `right`, `width`, `height`, `opacity`, `color` and `backgroundColor`. The `transform` property is not supported at this time.

If you are animating views that don't contain any sort of transparency you will see performance gains when animating large or otherwise complex view groups.

## Support

* Android: 7.0+

## Usage

Download it [here](https://github.com/deckameron/Ti.Android.Animator/blob/master/android/dist/ti.android.animator-android-1.0.0.zip?raw=true)

```javascript
var Animator = require('ti.android.animator');
    
var mainWindow = Ti.UI.createWindow({
	backgroundColor : 'white'
});
    
var animationView = Ti.UI.createView({
    	backgroundColor : 'red',
    	width : 100,
    	height : 100
});

animationView.addEventListener('click', function () {
	Animator.animate(animationView, {
		duration : 1000,
		easing : Animator.BOUNCE_OUT,
		width : 150,
		height : 150,
		backgroundColor : 'blue',
		opacity : 0.5,
		bottom : 0
	}, function () {
		Animator.animate(animationView, {
			duration : 1000,
			easing : Animator.BOUNCE_OUT,
			width : 100,
			height : 100,
			backgroundColor : 'red',
			opacity : 1,
			bottom : null
		});
	});
});

mainWindow.add(animationView);

mainWindow.open();
```

## Rotations

If you need to perform a rotation you can pass the `rotate` property which accepts a float. The `rotate` property is the angle you wish to rotate to; A positive value will result in a counter-clockwise rotation, while a negative value will result in a clockwise rotation.

Once a rotation has been performed subsequent rotations will be performed from its last rotation angle. To simplify multiple rotations you can pass values > 360. For example to do two complete rotations you can pass a value of 720.


## Layout Support

When animating a complex layout (such as a vertical layout inside a vertical layout) it may be necessary to specify which parent to propogate the animimations from, you can do this by setting `parentForAnimation` and passing the proxy that holds the views that should animate. This is especially useful in cases where you are animating inside of a `Ti.UI.ScrollView`.


## Easing Functions

The below easing functions can be accessed as you would any other Titanium constant. Assuming the above usage example you can access all of these by passing the below name to the module, such as in: `Animator.ELASTIC_IN_OUT`

* LINEAR (default)
* QUAD_IN
* QUAD_OUT
* QUAD_IN_OUT
* CUBIC_IN
* CUBIC_OUT
* CUBIC_IN_OUT
* QUART_IN
* QUART_OUT
* QUART_IN_OUT
* QUINT_IN
* QUINT_OUT
* QUINT_IN_OUT
* SINE_IN
* SINE_OUT
* SINE_IN_OUT
* CIRC_IN
* CIRC_OUT
* CIRC_IN_OUT
* EXP_IN
* EXP_OUT
* EXP_IN_OUT
* ELASTIC_IN
* ELASTIC_OUT
* ELASTIC_IN_OUT
* BACK_IN
* BACK_OUT
* BACK_IN_OUT
* BOUNCE_IN
* BOUNCE_OUT
* BOUNCE_IN_OUT
