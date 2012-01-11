
//------------------------------ Begin: Rotate the background images ------------------------------
var interval = 4000; 
var random_display = 0;
var image_dir = "./_resources/images/imageshow/";
var ImageNum = 0;
var img1 = "meilenwerk_zuerichsee_start_01.jpg";
var img2 = "meilenwerk_zuerichsee_start_02.jpg";
var img3 = "meilenwerk_zuerichsee_start_03.jpg";
var img4 = "meilenwerk_zuerichsee_start_04.jpg";


imageArray = new Array();
imageArray[ImageNum++] = new imageItem(image_dir + img1);
imageArray[ImageNum++] = new imageItem(image_dir + img1);
imageArray[ImageNum++] = new imageItem(image_dir + img2);
imageArray[ImageNum++] = new imageItem(image_dir + img3);
imageArray[ImageNum++] = new imageItem(image_dir + img4);



var number_of_image = imageArray.length;

function imageItem(image_location) {
	this.image_item = new Image();
	this.image_item.src = image_location;
}

function rotateImage(place) {
	var new_image = getNextImage();
	
	/* Falls IE, wende Microsoft-spezifischen Filter für Fadingeffekt an */
	if(document.all && !window.opera){
		document.all[place].style.filter="blendTrans(duration=2.3)";
		document.all[place].filters.blendTrans.Apply();
		document.all[place].src = new_image;
		document.all[place].filters.blendTrans.Play();
	}else document[place].src = new_image;
	
	var recur_call = "rotateImage('"+place+"');";
	timerID = setTimeout(recur_call, interval);
}

function get_ImageItemLocation(imageObj) {
	return(imageObj.image_item.src)
}

function getNextImage() {
	ImageNum = (ImageNum+1) % number_of_image;
	var new_image = get_ImageItemLocation(imageArray[ImageNum]);
	return(new_image);
}
//------------------------------- End: Rotate the background images -------------------------------



