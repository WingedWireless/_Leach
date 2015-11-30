var express = require ('express');
var MainServer = express();
MainServer.set ('')


MainServer.get ('/', function (request, response){
	response.send ('Hello');
});

MainServer.get ('/checknewupload/:id?/:password?', function (request, response){
	var id = request.params.id;
	var password = request.params.password;
	console.log (id + ' is Checking for new uploads');
	response.send ('Server->	Login ID: ' + id + '<br> Server->	Login Password: ' + password );
});

MainServer.get ('*', funcrion (request, reesponse){
	response.send ('404');
});

var Server = MainServer.listen(3000, function () {
	console.log ('Server on port 3000');
});