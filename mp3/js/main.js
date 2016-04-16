(function($){
	//var winWidth = $(window).width();
	var inputSize = 60;
	var genSize = 20;
	var generatedStates = [];

	//helper functions
	function initGenState() {
		for (var i = 0; i < genSize; i++) {
			generatedStates[i] = [];
			for (var j = 0; j < inputSize; j++) {
				generatedStates[i][j] = '0';
			};
		};
	}

	function initTable() {
		//$(winWidth).appendTo(table);
		var table = $('#initState');
		//$('<p>'+winWidth/inputSize+'</p>').appendTo(table);
		var tRow = $('<tr></tr>').appendTo(table).each(function() {
			for (var i = 0; i < inputSize; i++) {
				$('<td class="inactive"></td>').appendTo(this);
			};
		});

		//$('td').css('width', parseInt(winWidth/inputSize));
		//$('tr').css('height', parseInt(winWidth/inputSize));
	}

	function copyInitState() {
		for (var i = 0; i < generatedStates[0].length; i++) {
			if($('#initState td:eq('+ i +')').hasClass('active')) {
				generatedStates[0][i] = '1';
			}
		};
		$('#initState td')
	}

	function generateChildren() {
		copyInitState();
		if($('#generations').val() != '') {
			genSize = parseInt($('#generations').val());
		}

		for (var i = 1; i < generatedStates.length; i++) {
	 		for (var j = 0; j < generatedStates[i].length; j++) {
	 			if(j == 0) {
	 				generatedStates[i][j] = rules(['0', generatedStates[i-1][j], generatedStates[i-1][j+1]]);
	 			}
	 			else if(j == generatedStates[i].length-1) {
	 				generatedStates[i][j] = rules([generatedStates[i-1][j-1], generatedStates[i-1][j], '0']);
	 			}
	 			else {
	 				generatedStates[i][j] = rules([generatedStates[i-1][j-1], generatedStates[i-1][j], generatedStates[i-1][j+1]]);
	 			}
	 		};
		};
	}

	function rules(list) {
		list = list.join();
		var newState = '';
		if(list == "1,1,1") {
			newState = '0';
		}
		else if(list == "1,1,0") {
			newState = '0';
		}
		else if(list == "1,0,1") {
			newState = '0';
		}
		else if(list == "1,0,0") {
			newState = '1';
		}
		else if(list == "0,1,1") {
			newState = '1';
		}
		else if(list == "0,1,0") {
			newState = '1';
		}
		else if(list == "0,0,1") {
			newState = '1';
		}
		else if(list == "0,0,0") {
			newState = '0';
		}
		return newState;
	}

	function updateGenTable() {
		var table = $('#generatedState');
		for (var i = 0; i < generatedStates.length; i++) {
			var newRow = $('<tr></tr>').appendTo(table);
			for (var j = 0; j < generatedStates[i].length; j++) {

				if(generatedStates[i][j] == '1') {
					$('<td class="active"></td>').appendTo(newRow);
				}
				else {
					$('<td class="inactive"></td>').appendTo(newRow);
				}
			};
		};
	}

	//initialization functions
	initGenState();
	initTable();
	$('#loading').hide();

	//event functions
	$('#initState td').click(function() {
		if($(this).hasClass('active')) {
			$(this).removeClass('active').addClass('inactive');
		}
		else {
			$(this).removeClass('inactive').addClass('active');
		}
	});

	$('#generate').click(function() {
		$('#generatedState').hide();
		$('#generatedState tr').remove();
		initGenState();
		generateChildren();
		updateGenTable();
		$('#generatedState').show();
	})
	

})(jQuery);