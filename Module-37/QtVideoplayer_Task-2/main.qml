import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("QML_Videoplayer_model")

    Rectangle {
        anchors {
            left: parent.left;
            top: parent.top;
            right: parent.right;
            bottom: parent.bottom;
            bottomMargin: 50
        }

        color: "black"
    }

    ProgressBar {
        anchors {
            left: parent.left;
            right: parent.right;
            bottom: parent.bottom;
            bottomMargin: 45
        }
    }

    ButtonGroup {
        buttons: Row.children
    }

    Row {
        id: row

        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.verticalCenter: parent.bottom;
        anchors.verticalCenterOffset: -20;


        Button {
            text: "►"
        }
        Button {
            text: "▌▌"
        }
        Button {
            text: "██"
        }
        Button {
            text: "◄◄"
        }
        Button {
            text: "►►"
        }
    }
}
