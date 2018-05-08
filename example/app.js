var Animator = require('ti.android.animator');

var mainWindow = Ti.UI.createWindow({
    backgroundColor : 'white',
    exitOnClose : true
});

var viewToAnimate = Ti.UI.createView({
    height : 100,
    top : 0,
    backgroundColor : 'red'
});

var easingMethod = Animator.LINEAR;

var easeSelect = Ti.UI.createPicker({
    selectionIndicator : true,
    backgroundColor : '#757575'
});

var easeSelectView = Ti.UI.createView({
    height : 100,
    bottom : 0,
    backgroundColor : 'white'
});

easeSelect.add([
    Ti.UI.createPickerRow({ title : 'LINEAR' }),
    Ti.UI.createPickerRow({ title : 'QUAD_IN' }),
    Ti.UI.createPickerRow({ title : 'QUAD_OUT' }),
    Ti.UI.createPickerRow({ title : 'QUAD_IN_OUT' }),
    Ti.UI.createPickerRow({ title : 'CUBIC_IN' }),
    Ti.UI.createPickerRow({ title : 'CUBIC_OUT' }),
    Ti.UI.createPickerRow({ title : 'CUBIC_IN_OUT' }),
    Ti.UI.createPickerRow({ title : 'QUART_IN' }),
    Ti.UI.createPickerRow({ title : 'QUART_OUT' }),
    Ti.UI.createPickerRow({ title : 'QUART_IN_OUT' }),
    Ti.UI.createPickerRow({ title : 'QUINT_IN' }),
    Ti.UI.createPickerRow({ title : 'QUINT_OUT' }),
    Ti.UI.createPickerRow({ title : 'QUINT_IN_OUT' }),
    Ti.UI.createPickerRow({ title : 'SINE_IN' }),
    Ti.UI.createPickerRow({ title : 'SINE_OUT' }),
    Ti.UI.createPickerRow({ title : 'SINE_IN_OUT' }),
    Ti.UI.createPickerRow({ title : 'CIRC_IN' }),
    Ti.UI.createPickerRow({ title : 'CIRC_OUT' }),
    Ti.UI.createPickerRow({ title : 'CIRC_IN_OUT' }),
    Ti.UI.createPickerRow({ title : 'EXP_IN' }),
    Ti.UI.createPickerRow({ title : 'EXP_OUT' }),
    Ti.UI.createPickerRow({ title : 'EXP_IN_OUT' }),
    Ti.UI.createPickerRow({ title : 'ELASTIC_IN' }),
    Ti.UI.createPickerRow({ title : 'ELASTIC_OUT' }),
    Ti.UI.createPickerRow({ title : 'ELASTIC_IN_OUT' }),
    Ti.UI.createPickerRow({ title : 'BACK_IN' }),
    Ti.UI.createPickerRow({ title : 'BACK_OUT' }),
    Ti.UI.createPickerRow({ title : 'BACK_IN_OUT' }),
    Ti.UI.createPickerRow({ title : 'BOUNCE_IN' }),
    Ti.UI.createPickerRow({ title : 'BOUNCE_OUT' }),
    Ti.UI.createPickerRow({ title : 'BOUNCE_IN_OUT' }),
]);

easeSelect.addEventListener('change', function (e) {
    easingMethod = Animator[e.row.title];
});

viewToAnimate.addEventListener('singletap', function () {
    Animator.animate(viewToAnimate, {
        rotate : 180,
        backgroundColor : 'green',
        top : Ti.Platform.displayCaps.platformHeight - 199,
        width : "50%",
        opacity : 0.5,
        duration : 500,
        easing : easingMethod
    }, function () {
        Animator.animate(viewToAnimate, {
            rotate : 180,
            backgroundColor : 'red',
            top : 0,
            width : null,
            opacity : 1,
            duration : 500,
            easing : easingMethod
        });
    });
});

easeSelectView.add(easeSelect);

mainWindow.add(
    Ti.UI.createView({
        height : 1,
        backgroundColor : '#A5A5A5',
        bottom : 100
    })
);

mainWindow.add(easeSelectView);
mainWindow.add(viewToAnimate);
mainWindow.open();