var visu = function() {
	this.colors = {
		bg: '#262626', // Dark gray
		fg: '#F37D1A', // Awesome orange
		hl: '#2E2F2F', // Light gray for highlights
		tx: '#F2F2F2', // White-ish for text
	};
	this.framerate = 60;
    this.canvas = document.getElementById('canvas');
    this.ctx = canvas.getContext('2d');
}

var render = new visu();