var express = require('express');
var app = express();
var bodyParser = require('body-parser');

app.use(express.static('public'));
app.set('view engine', 'jade');

app.use(bodyParser.json()); 
app.use(bodyParser.urlencoded({ extended: true })); 


app.get('/', function (req, res) {
  res.render('index', { title: 'Hey', message: 'Hello there!'});
});

var ffi = require('./routes/ffi');
app.use('/ffi', ffi);


var server = app.listen(3000, function () {
  var host = server.address().address;
  var port = server.address().port;
  console.log('Web server listing at http://%s:%s', host, port);
});