.class Lcom/beginhigh19/p016j$for;
.super Landroid/webkit/WebChromeClient;
.source "SourceFile"


# annotations
.annotation system Ldalvik/annotation/EnclosingClass;
    value = Lcom/beginhigh19/p016j;
.end annotation

.annotation system Ldalvik/annotation/InnerClass;
    accessFlags = 0x2
    name = "for"
.end annotation


# instance fields
.field final synthetic fddo:Lcom/beginhigh19/p016j;


# direct methods
.method private constructor <init>(Lcom/beginhigh19/p016j;)V
    .locals 0

    iput-object p1, p0, Lcom/beginhigh19/p016j$for;->fddo:Lcom/beginhigh19/p016j;

    invoke-direct {p0}, Landroid/webkit/WebChromeClient;-><init>()V

    return-void
.end method

.method synthetic constructor <init>(Lcom/beginhigh19/p016j;Lcom/beginhigh19/p016j$fddo;)V
    .locals 0

    invoke-direct {p0, p1}, Lcom/beginhigh19/p016j$for;-><init>(Lcom/beginhigh19/p016j;)V

    return-void
.end method


# virtual methods
.method public onJsAlert(Landroid/webkit/WebView;Ljava/lang/String;Ljava/lang/String;Landroid/webkit/JsResult;)Z
    .locals 0

    const/4 p1, 0x1

    return p1
.end method
