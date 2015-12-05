var express = require ('express');
var MainServer = express();
var google = require('googleapis');
var googleAuth = require('google-auth-library');
var fs = require ('fs');
MainServer.set ('');



MainServer.get ('/', function (request, response){
	response.send ('Hello');
	console.log ('Someone is at Server home page');
});

MainServer.get('/checknewupload/:id?/:pwrd?', function (request, response){
	var id = request.params.id;
	var pwrd = request.params.pwrd;
	console.log (id + ' is Checking for new uploads');
	response.send ('Server->	Login ID: ' + id + '<br> Server->	Login Password: ' + pwrd );
    check_new_mail ();
	});

MainServer.get ('*', function (request, response){
	response.send ('404');
});
//223
//915
var Server = MainServer.listen(3000, function () {
	console.log ('Server on port 3000');
});

//-----------------------------
function check_new_mail (){
	//Read Client secret setup file
	fs.readFile('client_secret.json', function processClientSecrets(err, content) {
    if (err){console.log('Error loading client secret file: ' + err);return;}
	var credentials = JSON.parse(content);
    var SCOPES = ['https://www.googleapis.com/auth/gmail.readonly'];
    var clientSecret = credentials.web.client_secret;
    var clientId = credentials.web.client_id;
    var redirectUrl = credentials.web.redirect_uris[0];	
	var auth = new googleAuth();	
	var oauth2Client = new auth.OAuth2(clientId, clientSecret, redirectUrl);	
	
}); 
}