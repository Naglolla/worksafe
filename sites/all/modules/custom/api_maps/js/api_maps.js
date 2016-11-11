/* 
 * API Course module (JavaScript functions)
 */
(function ($) {
    // Fetch map (states) information.
    var request = $.ajax({
        type: "POST",
        url: Drupal.settings.basePath + "api/api/getMapInfo",
        dataType: "json",
        success: function(msg){
        }
    });
    request.done(function(data) {
        // Prepare Information to populate map.
        var apiMapStates = data['states'];
        var apiStatesColors = {};
        var apiColorsPalette = {};
        var apiGraphSeries = {};
        var apiGraphData = {};
        var apiGraphPalette = {};
        
        $.each(data['states'], function(key, value) {
            apiStatesColors[key] = value['color'];
            apiColorsPalette[value['color']] = value['color'];
        });
        $.each(data['graph'], function(key, value) {
            apiGraphData[value['color']] = value['label'];
            apiGraphPalette[value['color']] = value['color'];
        });
        
        // Create Graph Container only when Graph Entities exist.
        if (Object.keys(data['graph']).length > 0) {
            // Graph Info (Colors / Labels)
            apiGraphSeries = {
                attribute: 'fill',
                // Declare colors
                scale: apiGraphPalette,
                legend: {
                  vertical: true,
                  cssClass: 'jvectormap-legend-bg',
                  title: 'Color',
                  labelRender: function(v){ 
                    return apiGraphData[v];
                  }
                }
            };
        }

        $(document).ready(function() {
          $('div#api-usa-map').vectorMap({
                map: 'us_aea',
                // Disable both zoom methods (mouse & +/-)
                zoomOnScroll: false,
                zoomMax: 1,
                backgroundColor: 'none',
                // Region Tip Content
                onRegionTipShow: function(event, label, code) {
                  labelExist = typeof apiMapStates[code] !== 'undefined' && apiMapStates[code].hasOwnProperty('tip_info');
                  if (labelExist) {
                    label.html(
                      '<b>'+label.html()+'</b></br>'+
                      '<b></b>'+apiMapStates[code]['tip_info']
                    );
                  }
                },
                // Redirect (if redirection exist for state)
                onRegionClick: function(event, code) {
                  // Render State Action.
                  actionExist = typeof apiMapStates[code] !== 'undefined' && apiMapStates[code].hasOwnProperty('alt_action');  
                  if (actionExist) {
                    document.location.href = (apiMapStates[code]['alt_action']);
                  } else {
                    // Responsive: Hide all states and only display selected one.
                    if(document.body.clientWidth <= 600) {
                      $(".api-map-states-list-view .us-state-row").addClass("hide");
                      $('#' + code).removeClass("hide");
                    }
                    document.location.href = ('#' + code);
                    // Update responsive states select list.
                    $("#edit-states-list").val(code);
                  }
                },

                // Regions and Graph.
                series: {
                  regions: [
                    // Regions Colors
                    {
                        attribute: 'fill',
                        // Declare colors
                        scale: apiColorsPalette,
                        // States color.
                        values: apiStatesColors,
                    },
                    // Graph Info (Colors / Labels)
                    apiGraphSeries
                  ]
                },
                // Regions Default Color
                regionStyle: {
                    initial: {
                      fill: '#E1E1E1',
                    },
                    //hover: {
                      //fill: '#A5C3FF'
                    //}
                },

                // Region Labels (State ID's)
                labels: {
                  regions: {
                    render: function(code){
                      return code.split('-')[1];
                    },
                    // Better position some of the state's ID
                    offsets: function(code){
                      return {
                        'CA': [-10, 10],
                        'ID': [0, 40],
                        'OK': [25, 0],
                        'LA': [-20, 0],
                        'FL': [45, 0],
                        'KY': [10, 5],
                        'VA': [15, 5],
                        'MI': [30, 30],
                        'AK': [50, -25],
                        'HI': [25, 50],
                        'MD': [0, -15]
                      }[code.split('-')[1]];
                    }
                  }
                },
                // State ID's over every region.
                regionLabelStyle: {
                  initial: {
                    fill: '#464646'
                  },
                  hover: {
                    fill: 'black'
                  }
                },
          });
          
          // Map resize (responsive)
          var resizeMap = function(margin){
            if(document.body.clientWidth <= 600) {
                $('#api-usa-map').css('margin-bottom',margin);
                // Hide States below the map
                $(".api-map-states-list-view .us-state-row").addClass("hide");
              }else{
                $('#api-usa-map').css('margin-bottom',0);
                // Display States below the map
                $(".api-map-states-list-view .us-state-row").removeClass("hide");
              }
          }
          var offset = 50;
          var labelHeigh = $('.jvectormap-legend.jvectormap-legend-bg').height();
          resizeMap(labelHeigh+offset);
          $( window ).resize(function() {
            resizeMap(labelHeigh+offset);
          });
          
          // Select List for mobiles.
          $('#edit-states-list').change(function() {
            if ($(this).val() != 'null') {
              $code = $(this).val();
              // Render State Action.
              actionExist = typeof apiMapStates[$code] !== 'undefined' && apiMapStates[$code].hasOwnProperty('alt_action');  
              if (actionExist) {
                document.location.href = (apiMapStates[$code]['alt_action']);
              } else {
                // Responsive: Hide all states and only display selected one.
                $(".api-map-states-list-view .us-state-row").addClass("hide");
                $('#' + $code).removeClass("hide");
                document.location.href = ('#' + $code);
              }
            }
          });
          
        });
    });
})(jQuery);
