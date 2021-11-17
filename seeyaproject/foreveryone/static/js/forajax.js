$(document).ready(function () {
    showImages();
});
function showImages() {
    $.ajax({
        type: "GET",
        url: "ajax_get_img/",
        data: {},
        success: function (response) {
            console.log(response)
            let articles = response['photo']
            alert(response['photo'])
        }
    })
}
어떤파일인지 기억잘안남