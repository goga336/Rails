import qbs
CppApplication {
    Depends { name: "Qt.quick" }
    install: true
    property pathList qmlImportPaths: []

    files: [
        "datamanager.cpp",
        "datamanager.h",
        "main.cpp",
    ]

    Group {
        Qt.core.resourcePrefix: "v1/"
        fileTags: ["qt.qml.qml", "qt.core.resource_data"]
        files: ["Main.qml"]
    }
}
