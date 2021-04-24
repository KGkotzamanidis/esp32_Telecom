function req_login(){
    var xhr = new XMLHttpRequest();
    xhr.open("GET","/login",true);
    xhr.send();
}